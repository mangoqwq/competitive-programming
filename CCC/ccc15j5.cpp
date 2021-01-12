#include <bits/stdc++.h>
 
using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=251;
 
int dp[MAXN][MAXN];
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    dp[1][1]=1;
    for (int j=1;j<=m;++j){
        for (int i=1;i<=n;++i){
            if (i>=j) dp[i][j]+=dp[i-1][j-1]+dp[i-j][j];
        }
    }
    cout << dp[n][m] << '\n';
}