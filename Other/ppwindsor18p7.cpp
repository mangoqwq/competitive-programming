#include <bits/stdc++.h>

using namespace std;
int dp[1001];

int main(){
    int n; cin >> n;
    for (int i=1,a;i<n+1;++i){
        cin >> a;
        dp[i]=a;
        for (int k=0;k<i;++k){
            dp[i]=max(dp[i],dp[k]+dp[i-k]);
        }
    }
    cout << dp[n] << '\n';
}