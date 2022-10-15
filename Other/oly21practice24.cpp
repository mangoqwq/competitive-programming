#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e5+1;

struct Edge{ int to, w; };
vector<Edge> adj[MAXN];
int d[MAXN], in[MAXN], out[MAXN], T, up[MAXN][21], arr[MAXN];
int n, m, x[MAXN], y[MAXN], dist[MAXN], anc[MAXN], mx, cnt, goal, ans;

void dfs(int v, int p){
    in[v]=++T;
    up[v][0]=p;
    for (int i=1;i<=20;++i) up[v][i]=up[up[v][i-1]][i-1];
    for (auto [to,w]:adj[v]){
        if (to==p) continue;
        d[to]=d[v]+w;
        dfs(to,v);
    }
    out[v]=T;
}

bool is(int a, int b){ return in[a]<=in[b]&&out[a]>=out[b]; }

int lca(int a, int b){
    if (is(a,b)) return a;
    if (is(b,a)) return b;
    for (int i=20;i>=0;--i){
        if (!is(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}

int solve(int v, int p, int pre){
    for (auto [to,w]:adj[v]){
        if (to==p) continue;
        arr[v]+=solve(to,v,w);
    }
    if (arr[v]>=cnt&&pre>=goal) ans=1;
    return arr[v];
}

bool can(int val){
    cnt=0, ans=0; ms(arr,0);
    for (int i=1;i<=m;++i){
        if (dist[i]>val){
            cnt++;
            arr[x[i]]++, arr[y[i]]++;
            arr[anc[i]]-=2;
        }
    }
    goal=mx-val;
    solve(1,1,0);
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1;i<n;++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1,1);
    for (int i=1;i<=m;++i){
        cin >> x[i] >> y[i];
        anc[i]=lca(x[i],y[i]);
        dist[i]=d[x[i]]+d[y[i]]-2*d[anc[i]];
        mx=max(mx,dist[i]);
    }
    int lo=0, hi=3e8, mid;
    while (lo<hi){
        mid=lo+hi>>1;
        if (can(mid)) hi=mid;
        else lo=mid+1;
    }
    cout << lo << '\n';
}