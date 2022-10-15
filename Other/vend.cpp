#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

ll dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, cc; cin >> n >> cc;
    for (int i=1;i<=n;++i){
        int a, b, c, d; cin >> a >> b >> c >> d;
        for (int j=a+c;j<=cc;++j) dp[j]=max(dp[j],dp[j-a-c]+b+d);
        for (int j=cc;j>=a;--j) dp[j]=max(dp[j],dp[j-a]+b);
        for (int j=cc;j>=c;--j) dp[j]=max(dp[j],dp[j-c]+d);
    }
    cout << dp[cc] << '\n';
}