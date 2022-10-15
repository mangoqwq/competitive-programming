#include <bits/stdc++.h>

using namespace std;
long long dp[1000001];

int main(){
    int n; cin >> n;
    long long a;
    if (n==1){
        cin >> a;
        cout << max((long long)0,a);
        return 0;
    }
    for (int i=1;i<3;++i){
        cin >> a;
        dp[i]=max((long long)0,a);
    }
    dp[2]=max(dp[2],dp[1]);
    for (int i=3;i<n+1;++i){
        cin >> a;
        dp[i]=max(max(dp[i-1],dp[i-2]),dp[i-2]+a);
    }
    cout << max(dp[n],dp[n-1]) << '\n';
}