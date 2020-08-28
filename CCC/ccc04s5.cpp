#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=101;

char grid[MAXN][MAXN];
int dp[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    while (true){
        int r,c; cin >> r >> c;
        if (r==0 && c==0) break;
        for (int i=1;i<=r;++i){
            for (int j=1;j<=c;++j){
                cin >> grid[i][j];
                if (grid[i][j]=='.') grid[i][j]='0';
            }
        }
        ms(dp,-0x3f); dp[r][0]=0;
        int val;
        for (int col=1;col<=c;++col){
            for (int row=1;row<=r;++row){
                val=0;
                for (int i=row;i<=r;++i){
                    if (grid[i][col]=='*') break;
                    val+=grid[i][col]-'0';
                    dp[row][col]=max(dp[row][col],val+dp[i][col-1]);
                }
                val=0;
                for (int i=row;i>=1;--i){
                    if (grid[i][col]=='*') break;
                    val+=grid[i][col]-'0';
                    dp[row][col]=max(dp[row][col],val+dp[i][col-1]);
                }
            }
        }
        cout << dp[r][c] << '\n';
    }
}
