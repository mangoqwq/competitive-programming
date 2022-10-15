#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2001;

int dp[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int ans; cin >> ans;
    dp[1][1]=1;
    for (int i=2;i<=n;++i){
        for (int j=1;j<=i;++j){
            int a; cin >> a;
            dp[i][j]=1+dp[i-1][j]+dp[i-1][j-1]-dp[i-2][j-1];
            if (dp[i][j]<=k) ans=min(ans,a);
        }
        cout << '\n';
    }
    cout << ans << '\n';
} 
