#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

ll arr[MAXN],ans=0x3f3f3f3f3f3f3f3f,dp[MAXN];
ll n,k,cnt[MAXN],lower,upper;

void solve(ll c){
    dp[0]=dp[1]=cnt[0]=cnt[1]=0;
    for (int i=2;i<=n;++i){
        if (dp[i-2]+arr[i]-arr[i-1]-c<dp[i-1])
            dp[i]=dp[i-2]+arr[i]-arr[i-1]-c, cnt[i]=cnt[i-2]+1;
        else
            dp[i]=dp[i-1], cnt[i]=cnt[i-1];
    }
    lower=cnt[n];
    dp[0]=dp[1]=cnt[0]=cnt[1]=0;
    for (int i=2;i<=n;++i){
        if (dp[i-2]+arr[i]-arr[i-1]-c<=dp[i-1])
            dp[i]=dp[i-2]+arr[i]-arr[i-1]-c, cnt[i]=cnt[i-2]+1;
        else
            dp[i]=dp[i-1], cnt[i]=cnt[i-1];
    }
    upper=cnt[n];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // freopen("name.in","r",stdin);
    // freopen("name.out","w",stdout);
    cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> arr[i];
    ll l=0,r=1e9+5;
    while (l<=r){
        ll mid=(l+r)>>1;
        solve(mid);
        // cout << mid << " " << cnt[n] << " " << range[n] << " " << dp[n]+k*mid << '\n';
        if (lower<=k&&upper>=k) ans=min(ans,dp[n]+k*mid);
        if (lower>=k) r=mid-1;
        else l=mid+1;
    }
    cout << ans << '\n';
}