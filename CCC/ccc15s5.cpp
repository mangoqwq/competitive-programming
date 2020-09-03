#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=3005,MAXM=105;

int n, m, a[MAXN], b[MAXN];
int dp[MAXM][MAXM][2], last[MAXM][MAXM][2];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    cin >> m;
    for (int i=1;i<=m;++i) cin >> b[i];
    sort(b+1,b+1+m);
    ms(dp,-0x3f);  dp[1][m][0]=dp[1][m][1]=0; 
    for (int i=1;i<=n;++i){
        swap(dp,last);
        for (int l=1;l-1<=m;++l){
            for (int r=0;r<=m;++r){
                dp[l][r][0]=max(dp[l][r][0],last[l][r][1]); // oo
                dp[l][r][0]=max(dp[l][r][0],last[l][r+1][0]+b[r+1]); // o^o
                dp[l][r][0]=max(dp[l][r][0],last[l-1][r+1][1]+b[r+1]); // o^^o
                dp[l][r][1]=max(dp[l][r][1],last[l][r][0]+a[i]); // oo
                dp[l][r][1]=max(dp[l][r][1],last[l-1][r][1]+a[i]); // o^o
                dp[l][r][1]=max(dp[l][r][1],last[l-1][r+1][0]+a[i]+b[r+1]); // o^^o
                dp[l][r][1]=max(dp[l][r][1],dp[l][r][0]);
            }
        }
    }
    int ans=0;
    for (int l=1;l-1<=m;++l){
            for (int r=0;r<=m;++r){
                if (r-l<-1) continue;
                int curr=0;
                for (int i=(l+r+2)>>1;i<=r;++i) curr+=b[i];
                ans=max(ans,dp[l][r][1]+curr);
                if ((r-l+1)%2==1) ans=max(ans,dp[l][r][0]+curr+b[(l+r)>>1]);
            }
        }
    cout << ans << '\n';
}