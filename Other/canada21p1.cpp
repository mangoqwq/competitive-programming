#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int dp[MAXN][3];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i) ms(dp[i],0x3f);
        string s; cin >> s;
        s=" "+s;
        dp[0][0]=0;
        dp[0][1]=inf;
        dp[0][2]=inf;
        for (int i=1;i<=n;++i){
            dp[i][0]=dp[i-1][0]+(s[i]!='R');
            if (i>1) dp[i][1]=min(dp[i-1][0],dp[i-1][1])+(s[i]!='W');
            if (i>2) dp[i][2]=min(dp[i-1][1],dp[i-1][2])+(s[i]!='R');
        }
        cout << dp[n][2] << '\n';
    }
}