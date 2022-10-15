#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3005;

char grid[MAXN][MAXN];
int dp[MAXN][3], ans; // 1 horizontal, 2 vertical

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j) 
            cin >> grid[i][j];
    for (int k=2;k<=n+m;++k){
        ms(dp,0);
        int i, j;
        for (i=min(n,k-1),j=k-i;i>=1&&j<=m;--i,++j){
            // cout << i << " " << j << '\n';
            dp[i][0]=*max_element(dp[i+1],dp[i+1]+3);
            if (grid[i][j]!='G') continue;
            dp[i][1]=max(dp[i+1][0],dp[i+1][1])+(grid[i][j-1]=='R'&&grid[i][j+1]=='W');
            dp[i][2]=max(dp[i+1][0],dp[i+1][2])+(grid[i-1][j]=='R'&&grid[i+1][j]=='W');
        }
        i++;
        ans+=max({dp[i][0],dp[i][1],dp[i][2]});
        // cout << ans << " ";
        // ans=0;
    }
    cout << ans << '\n';
}