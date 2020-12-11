#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=101;

double dp[MAXN][MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c; cin >> a >> b >> c;
    for (int i=99;i>=0;--i){
        for (int j=99;j>=0;--j){
            for (int k=99;k>=0 && i+j+k>0;--k){
                dp[i][j][k]=(i+0.0)/(i+j+k)*(dp[i+1][j][k]+1)
                           +(j+0.0)/(i+j+k)*(dp[i][j+1][k]+1)
                           +(k+0.0)/(i+j+k)*(dp[i][j][k+1]+1);
            }
        }
    }
    printf("%.6f", dp[a][b][c]);
}