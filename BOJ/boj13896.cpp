#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1, L=16;

int up[MAXN][L+1], in[MAXN], out[MAXN], sz[MAXN], T;
vector<int> adj[MAXN];

int dfs(int v, int p){
    in[v]=++T;
    sz[v]=1;
    up[v][0]=p;
    for (int i=1;i<=L;++i) up[v][i]=up[up[v][i-1]][i-1];
    for (int to:adj[v]){
        if (to==p) continue;
        sz[v]+=dfs(to,v);
    }
    out[v]=T;
    return sz[v];
}

bool is(int a, int b){ return in[a]<=in[b] && out[a]>=out[b]; }

void solve(){
    int n, q, rt; cin >> n >> q >> rt;
    for (int i=1;i<=n;++i){
        adj[i].clear();
        ms(up[i],0);
        in[i]=out[i]=sz[i]=0;
    } T=0;
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    while (q--){
        int op, v; cin >> op >> v;
        if (op==0){
            rt=v;
        }
        if (op==1){
            int u=rt;
            if (u==v) cout << n << '\n';
            else if (is(v,u)){
                for (int i=L;i>=0;--i){
                    if (!is(up[u][i],v)) u=up[u][i];
                }
                cout << n-sz[u] << '\n';
            }
            else cout << sz[v] << '\n';
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i=1;i<=t;++i){
        cout << "Case #" << i << ":\n";
        solve();
    }
}