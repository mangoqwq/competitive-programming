#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=998244353;
ll dp[1001][1001];
ll arr[1001];

int main(){
    int n,k; cin >> n >> k;
    for (int i=0,a;i<n;++i){
        cin >> a;
        arr[a]++;
    }
    for (int i=0;i<=n;++i){
        dp[i][0]=1;
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=k;++j){
            dp[i][j]=(dp[i-1][j-1]*arr[i]+dp[i-1][j])%mod;
        }
    }
    cout << dp[n][k] << '\n';

    
}