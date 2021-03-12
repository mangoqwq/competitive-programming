#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=301;

int dp[MAXN][MAXN], a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        dp[i][i]=1;
        cin >> a[i];
    }    
    for (int sz=2;sz<=n;++sz){
        for (int l=1;l+sz-1<=n;++l){
            int r=l+sz-1;
            dp[l][r]=min(dp[l][r-1],dp[l+1][r])+(a[l]!=a[r]);
            for (int i=l;i<r;++i){
                dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]);
            }
        }
    }
    cout << dp[1][n] << '\n';
}