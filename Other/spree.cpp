#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1001;

int dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, t; cin >> n >> t;
    for (int i=1;i<=n;++i){
        int v, h; cin >> v >> h;
        for (int j=t;j>=h;--j) dp[j]=max(dp[j],dp[j-h]+v);
    }
    cout << dp[t] << '\n';
}