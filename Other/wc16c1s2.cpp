#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

struct Edge{ int to, w; };
vector<Edge> adj[MAXN];
int cost[MAXN], need[MAXN];

void dfs(int v, int p){
    for (auto [to,w]:adj[v]){
        if (to==p) continue;
        cost[to]=w;
        dfs(to,v);
        need[v]|=need[to];
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i=1;i<=n-1;++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for (int i=1;i<=k;++i){
        int a; cin >> a;
        need[a]=1;
    }
    dfs(1,1);
    int ans=0;
    for (int i=1;i<=n;++i) ans+=need[i]*cost[i];
    cout << ans << '\n';
}