#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5001;

ll dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ms(dp,0x3f); dp[1]=0;
    for (int i=1;i<=n;++i){
        int c, d; cin >> c >> d;
        d=min(d,n-i);
        for (int j=n;j>=i&&j>=d;--j){
            dp[j]=min(dp[j],dp[j-d]+c);
        }
    }
    cout << dp[n] << '\n';
}