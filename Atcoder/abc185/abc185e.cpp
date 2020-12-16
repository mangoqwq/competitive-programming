#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1001;

int a[MAXN], b[MAXN], dp[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=m;++i) cin >> b[i];
    for (int i=0;i<=n;++i){
        for (int j=0;j<=m;++j){
            if (i==0) dp[i][j]=j;
            else if (j==0) dp[i][j]=i;
            else dp[i][j]=min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+(a[i]!=b[j])});
        }
    }
    cout << dp[n][m] << '\n';
}