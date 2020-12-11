#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=101, MAXV=1e3+1;

ll dp[MAXN*MAXV], tot;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, w; cin >> n >> w;
    ms(dp, 0x3f); dp[0]=0;
    for (int i=1;i<=n;++i){
        ll w, v; cin >> w >> v;
        tot+=v;
        for (int j=tot;j>=v;--j)
            dp[j]=min(dp[j],dp[j-v]+w);
    }
    for (int i=tot;i>=0;--i){
        if (dp[i]<=w){ cout << i << '\n'; break; }
    }
}