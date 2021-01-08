#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=18;

bool close[1<<MAXN];
int dp[1<<MAXN];
vector<int> adj[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0;i<(1<<n);++i){
        close[i]=1;
        for (int j=0;j<n;++j){
            if (!(1&(i>>j))) continue;
            int cnt=0;
            for (int x:adj[j]) cnt+=1&(i>>x);
            if (cnt!=__builtin_popcount(i)-1) close[i]=0;
        }
    }
    ms(dp,0x3f), dp[0]=0;
    for (int i=0;i<(1<<n);++i){
        int vis=__builtin_popcount(i);
        if (close[i]) dp[i]=1;
        for (int j=i;j;j=(j-1)&i) dp[i]=min(dp[i],dp[i-j]+dp[j]);
    }
    cout << dp[(1<<n)-1] << '\n';
}