#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=10001, MAXD=1001;

ll dp[MAXN][MAXD], w[MAXN], val[MAXN], cnt[MAXN], item[MAXN], ans[MAXN];
int p;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, d; cin >> n >> d;
    assert(n<=1e3&&d<=1e3);
    for (int i=1;i<=n;++i){
        ll c, v, k, expo=1; cin >> c >> v >> k;
        if (c<0||k<0) continue;
        k=min(k,(ll)d);
        while (k>expo){
            if (expo*c>d) break;
            w[++p]=expo*c, val[p]=expo*v, cnt[p]=expo, item[p]=i;
            k-=expo, expo<<=1;
        }
        if (k*c>d) continue;
        w[++p]=k*c, val[p]=k*v, cnt[p]=k, item[p]=i;
    }
    for (int i=1;i<=p;++i){
        for (int j=0;j<=d;++j){
            dp[i][j]=dp[i-1][j];
            if (j-w[i]>=0) dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+val[i]);
        }
    }
    cout << dp[p][d] << '\n';
    int x=d;
    for (int i=p;i>=1;--i){
        if (dp[i][x]==dp[i-1][x]) continue;
        ans[item[i]]+=cnt[i], x-=w[i];
    }
    for (int i=1;i<=n;++i) cout << ans[i] << '\n';
}