#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+10;

ll a[MAXN], dp[MAXN][3];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    ms(dp,-0x3f);
    dp[1][0]=a[1], dp[2][1]=a[2], dp[3][0]=a[1]+a[3], dp[3][2]=a[3];
    for (int i=4;i<=n;++i){
        dp[i][0]=dp[i-2][0]+a[i];
        dp[i][1]=max(dp[i-3][0],dp[i-2][1])+a[i];
        dp[i][2]=max({dp[i-4][0],dp[i-3][1],dp[i-2][2]})+a[i];
    }
    if (n%2==0) cout << max(dp[n][1],dp[n-1][0]) << '\n';
    else cout << max({dp[n][2],dp[n-1][1],dp[n-2][0]}) << '\n';
}
