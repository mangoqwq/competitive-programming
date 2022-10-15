#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mod=1000000;
ll dp[31];
ll dp2[31];

void solve(int x){
    dp[x]=dp[x-2]+2*dp2[x-1];
    dp2[x]=dp[x-1]+dp2[x-2];
    dp[x]%=mod;
    dp2[x]%=mod;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    dp[0]=1; dp2[1]=1;
    for (int x=2;x<=30;++x){
        solve(x);
    }
    for (int t=1;t<=5;++t){
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}