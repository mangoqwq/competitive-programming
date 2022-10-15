#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll dp[1000001];

int main(){
    int n; cin >> n;
    ll power=1;
    dp[0]=1;
    while (power<=n){
        for (int i=power;i<=n;++i){
            dp[i]+=dp[i-power];
            dp[i]%=mod;
        }
        power*=2;
    }
    cout << dp[n] << '\n';
}