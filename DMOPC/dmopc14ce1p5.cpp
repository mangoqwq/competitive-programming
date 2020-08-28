#include <bits/stdc++.h>

using namespace std;
pair<int,int> dp[1001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int _=0,a,b,c;_<n;++_){
        cin >> a >> b >> c;
        while (a>=0){
            for (int i=1000;i>=c;--i){
                if (dp[i].first<dp[i-c].first+a){
                    dp[i].first=dp[i-c].first+a;
                    dp[i].second=dp[i-c].second+1;
                }
                else if (dp[i].first==dp[i-c].first+a){
                    dp[i].second=min(dp[i].second,dp[i-c].second+1);
                }
            }
            a-=b;
        }
    }
    int s; cin >> s;
    cout << dp[s].first << '\n';
    int mininum=dp[s].second;
    for (int i=0;i<s;++i){
        if (dp[i].first==dp[s].first){
            mininum=min(mininum,dp[i].second);
        }
    }
    cout << mininum << '\n';
}