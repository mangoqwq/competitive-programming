#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int n, m, ans[MAXN];
struct Edge{ int n, w;};
vector<Edge> adj[MAXN];

void dfs(int v, int p, int c){
    if (ans[p]==c) ans[v]=(c+1)%n+1;
    else ans[v]=c;
    for (auto [to,nc] :adj[v]){
        if (ans[to]) continue;
        dfs(to,v,nc);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1;i<=m;++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1,1,adj[1][0].w);
    for (int i=1;i<=n;++i) cout << ans[i] << '\n';
}