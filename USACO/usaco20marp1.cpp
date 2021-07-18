#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2005;

bool g[MAXN][MAXN];
ll dp[MAXN][2], last[MAXN][2], inv=mod/2+1;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int good=0;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            char c; cin >> c;
            g[i][j]=c=='.';
            good+=c=='.';
        }
    }
    dp[0][1]=1;
    for (int i=1;i<=good;++i) dp[0][1]=dp[0][1]*2%mod;
    for (int i=1;i<=n;++i){
        swap(dp,last); ms(dp,0);
        for (int j=1;j<=n+1;++j){
            last[j][1]=(last[j][1]+last[j-1][1])%mod;
        }
        for (int j=1;j<=n+1;++j){
            dp[j][0]=last[j][0]%mod;
            if (g[i][j-1]) dp[j][0]=(dp[j][0]+last[j-1][1]*inv)%mod;
            if (j==1) dp[j][0]=(dp[j][0]+last[j-1][1])%mod;
            if (g[i][j]) dp[j][1]=dp[j][0]*inv%mod;
        }
    }
    ll ans=0;
    for (int i=1;i<=n+1;++i){
        ans=(ans+dp[i][i<=n])%mod;
    }
    cout << ans << '\n';
}
