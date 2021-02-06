#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=601;

int w, h, n, x[MAXN], y[MAXN];
int dp[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> w >> h >> n;
    for (int i=1;i<=n;++i) cin >> x[i] >> y[i];
    for (int i=1;i<=w;++i){
        for (int j=1;j<=h;++j){
            dp[i][j]=i*j;
            for (int k=1;k<=n;++k){
                if (x[k]>i||y[k]>j) continue;
                dp[i][j]=min(dp[i][j],dp[i][j-y[k]]+dp[i-x[k]][y[k]]);
                dp[i][j]=min(dp[i][j],dp[i-x[k]][j]+dp[x[k]][j-y[k]]);
            }
        }
    }
    cout << dp[w][h] << '\n';
}