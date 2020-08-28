#include <bits/stdc++.h>

using namespace std;
int dp[10001][101];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m; cin >> n >> m;
    memset(dp,-0x3f,sizeof dp); dp[0][0]=0;
    for (int month=1,x,y,s,b;month<=n;++month){
        cin >> x >> y >> b >> s;
        for (int i=0;i<=100;++i){
            for (int k=i+1;k<=min(100,i+y);++k){ //selling
                dp[month][i]=max(dp[month][i],dp[month-1][k]+((k-i)*s));
            }
        }
        for (int i=100;i>=0;--i){
            for (int k=i;k>=max(0,i-x);--k){
                dp[month][i]=max(dp[month][i],dp[month][k]-(i-k)*b);
            }
            for (int k=max(0,i-x);k<i;++k){ //buying
                dp[month][i]=max(dp[month][i],dp[month-1][k]-((i-k)*b));
            }
            dp[month][i]=max(dp[month][i],dp[month-1][i]);
        }
        for (int i=0;i<=100;++i){
            if (dp[month][i]!=-0x3f3f3f3f)dp[month][i]-=i*m;
        }
        
    }
    int ans=0;
    for (int i=0;i<=100;++i){
        //cout << dp[n][i]+i*m << " ";
        ans=max(ans,dp[n][i]+i*m);
    }
    cout << ans << '\n';
}