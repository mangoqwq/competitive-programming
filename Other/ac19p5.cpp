#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int arr[1502][1502];
int dp[1502][1502];

int solve(int x,int y){
    if (dp[x][y]!=-1) return dp[x][y];
    if (arr[x][y]<arr[x+1][y]){
        dp[x][y]=max(dp[x][y],1+solve(x+1,y));
    }
    if (arr[x][y]<arr[x-1][y]){
        dp[x][y]=max(dp[x][y],1+solve(x-1,y));
    }
    if (arr[x][y]<arr[x][y+1]){
        dp[x][y]=max(dp[x][y],1+solve(x,y+1));
    }
    if (arr[x][y]<arr[x][y-1]){
        dp[x][y]=max(dp[x][y],1+solve(x,y-1));
    }
    return dp[x][y];
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    memset(dp,-1,sizeof dp);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        for (int k=1;k<=n;++k){
            cin >> arr[i][k];
        }
    }
    int ans=-1;
    for (int i=1;i<=n;++i){
        for (int k=1;k<=n;++k){
            ans=max(ans,solve(i,k)+1);
        }
    }
    cout << ans << '\n';

}