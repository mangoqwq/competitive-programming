#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1, L=17;

int n, g, f, ans1, ans2, ans3=0x3f3f3f3f;
bool vis[MAXN];
vector<int> adj[MAXN];
int in[MAXN], out[MAXN], up[MAXN][L+1], T, d[MAXN];

int dfs(int v, int p){
    in[v]=++T;
    up[v][0]=p;
    for (int i=1;i<=L;++i) up[v][i]=up[up[v][i-1]][i-1];
    for (int to:adj[v]){
        if (to==p) continue;
        d[to]=d[v]+1;
        vis[v]|=dfs(to,v);
    }
    out[v]=T;
    return vis[v];
}

bool anc(int a, int b){ return in[a]<=in[b] && out[a]>=out[b]; }

int lca(int a, int b){
    if (anc(a,b)) return a;
    if (anc(b,a)) return b;
    for (int i=L;i>=0;--i) if (!anc(up[a][i],b)) a=up[a][i];
    return up[a][0];
}

int dist(int a, int b){ return d[a]+d[b]-2*d[lca(a,b)]; }
bool cmp(int a, int b){ return in[a]<in[b]; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> g >> f;
    for (int i=1,a;i<=g;++i) cin >> a, vis[a]=1;
    for (int i=1,a,b;i<=n-1;++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    for (int i=1;i<=n;++i){
        if (vis[i]){
            ans2++;
            ans3=min(ans3,dist(i,f));
            ans1=max(ans1,d[i]);
        }
    }
    cout << min(ans2*2-ans1-2,ans2+ans3-1) << '\n';
}