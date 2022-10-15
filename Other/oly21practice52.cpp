#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=60001;

int dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, w; cin >> n >> w;
    int tot=0, cost=0;
    ms(dp,0x3f), dp[0]=0;
    for (int i=1;i<=n;++i){
        int a, b; cin >> a >> b;
        tot+=a; cost+=b;
        for (int j=MAXN-1;j>=b;--j) dp[j]=min(dp[j],dp[j-b]+a);
    }
    for (int i=MAXN-2;i>=0;--i) dp[i]=min(dp[i],dp[i+1]);
    int sub=max(0,cost-w);
    cout << tot-dp[sub] << '\n';
}