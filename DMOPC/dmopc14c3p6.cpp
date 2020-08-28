#include <bits/stdc++.h>

using namespace std;
int dp[10001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int customers, time; cin >> customers >> time;
    for (int i=0,p1,v1,p2,v2,p3,v3; i<customers; ++i){
        cin >> p1 >> v1 >> p2 >> v2 >> p3 >> v3;
        for (int i=time;i>=p1;--i){
            dp[i]=max(dp[i-p1]+v1,dp[i]);
            if (i>=p2){
                dp[i]=max(dp[i-p2]+v2,dp[i]);
            }
            if (i>=p3){
                dp[i]=max(dp[i-p3]+v3,dp[i]);
            }
        }
    }
    cout << dp[time] << '\n';
}