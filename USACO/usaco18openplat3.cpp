#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5e4+1, L=16;

struct Edge{ int n, id; };
vector<Edge> adj[MAXN];
vector<int> up[MAXN], down[MAXN];
set<int> s[MAXN];
int ans[MAXN], in[MAXN], out[MAXN], st[MAXN][L+1], T;

void dfs0(int v, int p){
    in[v]=++T;
    st[v][0]=p;
    for (int i=1;i<=L;++i) st[v][i]=st[st[v][i-1]][i-1];
    for (Edge to:adj[v]){
        if (to.n==p) continue;
        dfs0(to.n,v);
    }
    out[v]=T;
}

bool is(int a, int b){ return in[a]<=in[b] && out[a]>=out[b]; }

int lca(int a, int b){
    if (is(a,b)) return a;
    if (is(b,a)) return b;
    for (int i=L;i>=0;--i) if (!is(st[a][i],b)) a=st[a][i];
    return st[a][0];
}

void dfs(int v, int p){
    for (Edge to:adj[v]){
        if (to.id==p) continue;
        dfs(to.n,to.id);
        if (s[v].size()<s[to.n].size()) swap(s[v],s[to.n]);
        for (int x:s[to.n]) s[v].insert(x);
    }
    for (int x:up[v]) s[v].insert(x);
    for (int x:down[v]) s[v].erase(x), s[v].erase(x);
    if (s[v].empty()) ans[p]=-1;
    else ans[p]=*s[v].begin();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1,a,b;i<=n-1;++i){
        cin >> a >> b;
        adj[a].push_back({b,i});
        adj[b].push_back({a,i});
    }
    dfs0(1,1);
    for (int i=1,a,b,w;i<=m;++i){
        cin >> a >> b >> w;
        up[a].push_back(w); up[b].push_back(w);
        down[lca(a,b)].push_back(w);
    }
    dfs(1,0);
    for (int i=1;i<=n-1;++i) cout << ans[i] << '\n';
}