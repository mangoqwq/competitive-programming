#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=998244353, seed=131, MAXN=2e5+1;

ll n, k, l[11], r[11], dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1;i<=k;++i) cin >> l[i] >> r[i];
    dp[1]=1;
    for (int i=1;i<=n;++i){
        dp[i]+=dp[i-1]; dp[i]%=mod;
        for (int j=1;j<=k;++j) dp[i]+=(dp[max(i-l[j],0LL)]-dp[max(i-r[j]-1,0LL)]+mod)%mod, dp[i]%=mod;
    }
    cout << (dp[n]-dp[n-1]+mod)%mod;
}