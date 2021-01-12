#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<ll,ll> pll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

ll val[MAXN];
ll best[MAXN];
vector<int> adj[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i){
        cin >> val[i];
    }
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    ll ans=LLONG_MIN;
    ms(best,0x3f);
    for (int v=1;v<=n;++v){
        ans=max(ans,val[v]-best[v]);
        best[v]=min(best[v],val[v]);
        for (int to:adj[v]){
            best[to]=min(best[to],best[v]);
        }
    }
    cout << ans << '\n';
}