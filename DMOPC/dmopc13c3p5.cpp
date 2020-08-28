#include <bits/stdc++.h>

using namespace std;
int dp[101][301]; //dp[food][minutes]

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    short minutes, food, n; cin >> minutes >> food >> n;
    int value;
    for (short _=0, time, eat; _<n; ++_){
        cin >> value >> time >> eat;
        for (short i=food;i>=eat;--i){
            for (short k=minutes;k>=time;--k){
                dp[i][k]=max(dp[i][k],dp[i-eat][k-time]+value);
            }
        }
    }
    cout << dp[food][minutes] << '\n';
}