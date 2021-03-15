#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=4e4+1, L=15;

int n, q, in[MAXN], out[MAXN], T, up[MAXN][L+1], d[MAXN];
struct Edge{ int to, w; };
vector<Edge> adj[MAXN];

void dfs(int v, int p){
    in[v]=++T;
    up[v][0]=p;
    for (int i=1;i<=L;++i) up[v][i]=up[up[v][i-1]][i-1];
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
    for (int i=L;i>=0;--i){
        if (!is(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n-1;++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1,1);
    cin >> q;
    while (q--){
        int a, b; cin >> a >> b;
        cout << d[a]+d[b]-2*d[lca(a,b)] << '\n';
    }
}