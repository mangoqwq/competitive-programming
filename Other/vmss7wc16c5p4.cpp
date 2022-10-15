#include <bits/stdc++.h>

using namespace std;
int dp[100001];

int main(){
    int uwu; cin >> uwu;
    dp[0]=1;
    for (int i=0,a;i<3;++i){
        cin >> a;
        for (int ii=a;ii<100001;++ii){
            if (dp[ii-a]){
                dp[ii]=max(dp[ii],dp[ii-a]+1);
            }
        }
    }
    cout << dp[uwu]-1 << '\n';
}