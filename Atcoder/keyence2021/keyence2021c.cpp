#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=998244353, seed=131, MAXN=5005;

char grid[MAXN][MAXN];
ll dp[MAXN][MAXN];

ll fpow(ll b, ll e){
    ll ret=1;
    while (e){
        if (e&1) ret=ret*b%mod;
        b=b*b%mod, e>>=1;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int h, w, k; cin >> h >> w >> k;
    for (int i=1;i<=k;++i){
        int x, y; cin >> x >> y;
        cin >> grid[x][y];
    }
    ll inv=fpow(3,mod-2);
    dp[1][1]=fpow(3,h*w-k);
    for (int i=1;i<=h;++i){
        for (int j=1;j<=w;++j){
            if (grid[i][j]=='R'){
                dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
            }
            else if (grid[i][j]=='D'){
                dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
            }
            else if (grid[i][j]=='X'){
                dp[i][j+1]=(dp[i][j+1]+dp[i][j])%mod;
                dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
            }
            else{
                dp[i][j+1]=(dp[i][j+1]+dp[i][j]*inv%mod)%mod;
                dp[i][j+1]=(dp[i][j+1]+dp[i][j]*inv%mod)%mod;
                dp[i+1][j]=(dp[i+1][j]+dp[i][j]*inv%mod)%mod;
                dp[i+1][j]=(dp[i+1][j]+dp[i][j]*inv%mod)%mod;
            }
        }
    }
    cout << dp[h][w] << '\n';
}