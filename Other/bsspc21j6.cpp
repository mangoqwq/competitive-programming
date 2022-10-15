#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5e5+1;

ll val[MAXN], st[MAXN], dp[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p){
    st[v]=val[v];
    vector<ll> a={0,0,0};
    for (int to:adj[v]){
        if (to==p) continue;
        dfs(to,v);
        st[v]+=st[to];
        dp[v]+=st[to];
        a.push_back(dp[to]-st[to]);
    }
    sort(a.begin(),a.end());
    for (int i=0;i<(v==1?3:2);++i) dp[v]+=a[i];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=2;i<=n;++i) cin >> val[i];
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    cout << dp[1] << '\n';
}