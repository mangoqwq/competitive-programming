#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3001;

ll dp[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> dp[i][i];
    for (int len=2;len<=n;++len){
        for (int l=1,r=len;r<=n;++l,++r){
            dp[l][r]=max(dp[r][r]-dp[l][r-1],dp[l][l]-dp[l+1][r]);
        }
    }
    cout << dp[1][n] << '\n';
}