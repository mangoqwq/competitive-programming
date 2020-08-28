#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=3001;

ll dp[2][MAXN][MAXN]; //0 is X, 1 is Y; 0 maximize X-Y, 1 minimize X-Y;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> dp[0][i][i];
        dp[1][i][i]=dp[0][i][i]*-1;
    }
    for (int len=2;len<=n;++len){
        for (int l=1,r=len;r<=n;++l,++r){
            dp[0][l][r]=max(dp[1][l][r-1]+dp[0][r][r],dp[1][l+1][r]+dp[0][l][l]);
            dp[1][l][r]=min(dp[0][l][r-1]+dp[1][r][r],dp[0][l+1][r]+dp[1][l][l]);
        }
    }
    cout << dp[0][1][n] << '\n';


}