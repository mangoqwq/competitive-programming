#include <bits/stdc++.h>

using namespace std;
int dp[1001];

int main(){
    short cages, minutes,princesses,song; cin >> cages >> minutes;
    for (int i=0;i<cages;++i){
        cin >> princesses >> song;
        for (int i=minutes;i-song>=0;--i){
            dp[i]=max(dp[i],dp[i-song]+princesses);
        }
    }
    cout << dp[minutes] << '\n';
}