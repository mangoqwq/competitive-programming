#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXC=10'002;

ll dp[2][MAXC];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,c; cin >> n >> c;
    c++;
    fill(begin(dp[1]),end(dp[1]),1); dp[1][0]=0;
    for (int i=2;i<=n;++i){
        for (int j=1;j<=c;++j){
            dp[i%2][j]=(dp[i%2][j-1]+(dp[(i+1)%2][j]-dp[(i+1)%2][max(j-i,0)]+mod)%mod)%mod;
        }
    }
    cout << dp[n%2][c]-dp[n%2][c-1] << '\n';
}