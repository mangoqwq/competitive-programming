#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1, L=18;

vector<int> graph[MAXN], adj[MAXN*2];
int stk[MAXN], top, in[MAXN], low[MAXN], T, dummy;
int tin[2*MAXN], tout[2*MAXN], up[2*MAXN][L+1], d[2*MAXN];
int n, m; 
int q[2*MAXN];

void dfs(int curr, int prev=-1){
    in[curr]=low[curr]=++T; stk[++top]=curr;
    for (int x:graph[curr]){
        if (!in[x]){
            dfs(x,curr); low[curr]=min(low[curr],low[x]);
            if (low[x]==in[curr]){
                dummy++;
                for (int a=0;a!=x;){
                    a=stk[top--]; adj[dummy].push_back(a), adj[a].push_back(dummy);
                }
                adj[dummy].push_back(curr); adj[curr].push_back(dummy);
            }
        }
        else low[curr]=min(low[curr],in[x]);
    }
}

void dfs1(int curr, int prev){
    tin[curr]=++T;
    d[curr]=d[prev]+(curr<=n);
    up[curr][0]=prev;
    for (int i=1;i<=L;++i) up[curr][i]=up[up[curr][i-1]][i-1];
    for (int x:adj[curr]){
        if (x==prev) continue;
        dfs1(x,curr);
    }
    tout[curr]=T;
}

bool is(int a, int b){ return tin[a]<=tin[b] && tout[a]>=tout[b]; }
bool cmp(int a, int b){ return tin[a]<tin[b]; }

int lca(int a, int b){
    if (is(a,b)) return a;
    if (is(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!is(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}

int dist(int a, int b){
    return d[a]+d[b]-2*d[lca(a,b)];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> n >> m;
        for (int i=1;i<=n;++i) graph[i].clear();
        for (int i=1;i<=2*n;++i) adj[i].clear();
        ms(stk,0); top=-1; ms(in,0); ms(low,0);  T=0; dummy=n;
        ms(tin,0); ms(tout,0); ms(up,0); ms(d,0);
        for (int i=1,a,b;i<=m;++i){
            cin >> a >> b;
            if (a==b) continue;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs(1);
        T=0; dfs1(1,1);
        int Q; cin >> Q;
        while (Q--){
            int s; cin >> s;
            for (int i=1;i<=s;++i) cin >> q[i];
            sort(q+1,q+1+s,cmp);
            ll tot=dist(q[1],q[s]);
            for (int i=2;i<=s;++i) tot+=dist(q[i],q[i-1]);
            cout << tot/2 + (lca(q[1],q[s])<=n) - s << '\n';
        }
    }
}