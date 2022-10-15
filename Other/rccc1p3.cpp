#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1001;

struct DSU{
    int p[MAXN];
    int Find(int v){ return (p[v]==v?v:p[v]=Find(p[v])); }
    bool Union(int a, int b){
        a=Find(a), b=Find(b);
        if (a==b) return 0;
        return p[b]=a, 1;
    }
} dsu;
vector<int> adj[MAXN];
vector<pii> ans;

int par[MAXN], in[MAXN], out[MAXN], T;
int pos[MAXN], val[MAXN], ch[MAXN];
// pos gets position of value 
// val gets value at that position
queue<int> q;
vector<int> poss, vals;
map<int,int> mp;

bool is_anc(int a, int b){ return in[a]<=in[b] && out[a]>=out[b]; }

void dfs(int v){
    in[v]=++T;
    for (int to:adj[v]){
        if (to==par[v]) continue;
        par[to]=v;
        ch[v]++;
        dfs(to);
    }
    if (ch[v]==0) q.push(v);
    poss.push_back(v), vals.push_back(val[v]);
    out[v]=T;
}

void solve(int rt){
    if (adj[rt].size()==0) return;
    poss.clear(), vals.clear();
    while (!q.empty()) q.pop();
    dfs(rt);
    sort(poss.begin(),poss.end());
    sort(vals.begin(),vals.end());
    for (int i=0;i<poss.size();++i) mp[poss[i]]=vals[i];
    while (!q.empty()){
        int v=q.front(); q.pop(); // destination
        int u=pos[mp[v]]; // start
        ch[par[v]]--;
        if (ch[par[v]]==0) q.push(par[v]);
        vector<int> vec, vec1;
        while (true){ // u -> lca
            vec.push_back(u);
            if (is_anc(u,v)) break;
            u=par[u];
        }
        while (v!=u) { // v -> lca, then reverse
            vec1.push_back(v);
            v=par[v];
        }
        for (int i=vec1.size()-1;i>=0;--i) vec.push_back(vec1[i]);
        for (int i=1;i<vec.size();++i){
            int a=vec[i], b=vec[i-1];
            ans.push_back({a,b});
            swap(val[a],val[b]);
            swap(pos[val[a]],pos[val[b]]);
        }
    }
}

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i){
        int a; cin >> a;
        pos[a]=i;
        val[i]=a;
    }
    iota(dsu.p,dsu.p+1+n,0);
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        if (dsu.Union(a,b)){
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    for (int i=1;i<=n;++i){
        if (par[i]) continue;
        par[i]=i, solve(i);
    }
    cout << ans.size() << '\n';
    for (int i=1;i<=n;++i) cout << val[i] << " ";
    cout << '\n';
    for (auto [a,b]:ans) cout << a << " " << b << '\n';
}