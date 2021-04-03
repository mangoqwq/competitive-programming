#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1001;

ll dp[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        for (int i=0;i<=n;++i) for (int j=1;j<=k;++j) dp[j][i]=1;
        for (int i=2;i<=k;++i){
            for (int j=1;j<=n;++j){
                for (int x=j;x>=1;--x){
                    dp[i][j]+=dp[i-1][n-x];
                    dp[i][j]%=mod;
                }
            }
        }
        cout << dp[k][n] << '\n';
    }  
}