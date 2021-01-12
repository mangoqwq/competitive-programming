#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=251, MAXW=250001;

int dp[MAXW];
double ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, W; cin >> n >> W;
    ms(dp,-0x3f), dp[0]=0;
    for (int i=1;i<=n;++i){
        int w, t; cin >> w >> t;
        if (w>=W) ans=max(ans,(double)t/w);
        for (int i=n*W;i>=w;--i) dp[i]=max(dp[i],dp[i-w]+t);
    }
    for (int i=W;i<=n*W;++i) ans=max(ans,(double)dp[i]/i);
    cout << (int)(ans*1000) << '\n';
}