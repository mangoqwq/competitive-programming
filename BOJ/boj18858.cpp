#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=998244353, inf=0x3f3f3f3f, MAXN=1001, MAXM=101;

ll dp[MAXM][MAXM], last[MAXM][MAXM];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=m;++i) dp[i][m]=1;
    for (int i=2;i<=n;++i){
        swap(dp,last);
        for (int j=1;j<=m;++j){
            for (int k=1;k<=m;++k){
                last[j][k]=(last[j][k]+last[j][k-1])%mod;
            }
        }
        for (int j=1;j<=m;++j){
            for (int k=1;k<=m;++k){
                if (j>=k) dp[j][k]=last[k][m];
                if (j<k) dp[j][k]=(last[k][m]-last[k][k-1]+mod)%mod;
            }
        }
    }
    int ans=0;
    for (int i=1;i<=m;++i){
        for (int j=1;j<=m;++j){
            ans=(ans+dp[i][j])%mod;
        }
    }
    cout << ans << '\n';
}