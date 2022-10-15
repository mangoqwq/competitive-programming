#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,arr[1000001],dp[1000001];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
    }
    dp[n]=1;
    for (int i=n-1;i>=1;--i){
        if (i+arr[i]+1>n){
            dp[i]=dp[i+1];
            continue;
        }
        dp[i]=max(dp[i+1],1+dp[i+arr[i]+1]);
    }
    cout << dp[1] << '\n';
}