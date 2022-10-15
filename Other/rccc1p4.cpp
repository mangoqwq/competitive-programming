#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5002;

int dp[MAXN][MAXN];
int val[MAXN], a[MAXN], b[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ms(dp,0x3f);
    int n; cin >> n; val[n+1]=5000;
    for (int i=1;i<=n;++i) cin >> val[i];
    for (int i=1;i<=n;++i) cin >> a[i] >> b[i];
    dp[1][0]=0;
    for (int i=1;i<=n;++i){
        for (int j=val[i];j>=0;--j) dp[i][j]=min(dp[i][j],dp[i][j+1]);
        for (int j=0;j<=5000;++j){
            dp[i+1][min(j*b[i],val[i+1])]=min(dp[i+1][min(j*b[i],val[i+1])],dp[i][max(0,val[i]-j*a[i])]+j);
        }
    }
    cout << *min_element(dp[n+1],dp[n+1]+1+val[n+1]) << '\n';
}