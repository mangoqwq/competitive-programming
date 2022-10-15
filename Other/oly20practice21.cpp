#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=205;
const ll inf=0x3f3f3f3f3f3f3f3f;

ll x[MAXN], t[MAXN], dp[MAXN][MAXN][2][MAXN], tmp; int ans=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; ll l; cin >> n >> l;
    for (int i=1;i<=n;++i) cin >> x[i];
    for (int i=1;i<=n;++i) cin >> t[i];
    x[n+1]=l;
    ms(dp,0x3f); dp[0][n+1][0][0]=0;
    for (int i=0;i<=n;++i){
        for (int j=n+1;j>i;--j){
            for (int k=0;k<=n;++k){
                if (i==0) continue;
                ll &curr=dp[i][j][0][k];
                curr=min({curr,dp[i-1][j][0][k]+x[i]-x[i-1],dp[i-1][j][1][k]+l-x[j]+x[i]});
                if (k==0) continue;
                tmp=dp[i-1][j][0][k-1]+x[i]-x[i-1];
                if (tmp<=t[i]) curr=min(curr,tmp);
                tmp=dp[i-1][j][1][k-1]+l-x[j]+x[i];
                if (tmp<=t[i]) curr=min(curr,tmp);
                if (curr!=inf) ans=max(ans,k);
            }
            for (int k=0;k<=n;++k){
                if (j==n+1) continue;
                ll &curr=dp[i][j][1][k];
                curr=min({curr,dp[i][j+1][0][k]+x[i]+l-x[j],dp[i][j+1][1][k]+x[j+1]-x[j]});
                if (k==0) continue;
                tmp=dp[i][j+1][1][k-1]+x[j+1]-x[j];
                if (tmp<=t[j]) curr=min(curr,tmp);
                tmp=dp[i][j+1][0][k-1]+x[i]+l-x[j];
                if (tmp<=t[j]) curr=min(curr,tmp);
                if (curr!=inf) ans=max(ans,k);
            }
        }
    }
    cout << ans << '\n';
}