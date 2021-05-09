#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1, L=20;

vector<int> req[MAXN], adj[MAXN];
int par[MAXN];
int Find(int x){ return par[x]==x?x:par[x]=Find(par[x]); }
void Union(int a, int b){
    a=Find(a), b=Find(b);
    if (a!=b) par[b]=a, adj[a].push_back(b);
}
int up[MAXN][L+1], in[MAXN], out[MAXN], T, val[MAXN];
void build(int v, int p){
    in[v]=++T;
    up[v][0]=p;
    for (int i=1;i<=L;++i) up[v][i]=up[up[v][i-1]][i-1];
    for (int to:adj[v]){
        build(to,v);
    }
    out[v]=T;
}
bool is_anc(int a, int b){ return in[a]<=in[b]&&out[a]>=out[b]; }
int lca(int a, int b){
    if (is_anc(a,b)) return a;
    if (is_anc(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!is_anc(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}
int collect(int v){
    for (int to:adj[v]) val[v]+=collect(to);
    return val[v];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        req[b].push_back(a);
    }
    for (int i=1;i<=n;++i) par[i]=i;
    for (int i=1;i<=n;++i){
        for (int j:req[i]){
            Union(i,j);
        }
    }
    for (int i=1;i<=n;++i) if (par[i]==i) build(i,i);
    for (int i=1;i<=n;++i){
        if (req[i].empty()) continue;
        sort(req[i].begin(),req[i].end(),[](int a, int b){ return in[a]<in[b]; });
        val[i]--; val[req[i][0]]++;
        for (int j=1;j<req[i].size();++j){
            int a=req[i][j], b=req[i][j-1];
            val[a]++, val[lca(a,b)]--;
        }
    }
    for (int i=1;i<=n;++i) if (par[i]==i) collect(i);
    cout << accumulate(val+1,val+1+n,0LL) << '\n';
}