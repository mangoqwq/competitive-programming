#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
ll dp[2][5001];


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n,time; cin >> n >> time;
    for (int ii=0,g,h,q,t;ii<n;++ii){
        cin >> g >> h >> q >> t;
        for (int i=5000;i>=0;--i){
            if (i<h) dp[0][i]=LLONG_MIN;
            else dp[0][i]=dp[1][i-h]+g;
        }
        for (int i=t;i<=5000;++i){
            dp[0][i]=max(dp[0][i],dp[0][i-t]+q);
        }
        for (int i=0;i<=5000;++i){
            dp[1][i]=max(dp[1][i],dp[0][i]);
        }
        // for (int i=0;i<=time;++i){
        //     cout << dp[0][i] << " ";
        // }
        // cout << '\n';
        // for (int i=0;i<=time;++i){
        //     cout << dp[1][i] << " ";
        // }
        // cout << '\n';
    }
    
    cout << dp[1][time] << '\n';
}