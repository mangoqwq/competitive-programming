#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int arr[201],dp[201][201];

int solve(int l, int r){
    if (dp[l][r]!=-1) return dp[l][r];
    if (l+1==r) return dp[l][r]=0;
    int ans=0;
    for (int i=l+1;i<=r-1;++i){
        ans=max(ans,arr[l]+arr[r]+arr[i]+solve(l,i)+solve(i,r));
    }
    return dp[l][r]=ans;
}


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    while (true){
        int n; cin >> n;
        if (n==0) return 0;
        for (int i=0;i<n;++i){
            cin >> arr[i];
        }
        memset(dp,-1,sizeof dp);
        cout << solve(0,n-1) << '\n';
    }
}