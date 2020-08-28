#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e6+1;

ll arr[MAXN], pre[MAXN], suf[MAXN], dp[MAXN], dp1[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> arr[i];
    ll temp=0;
    for (int i=1;i<=n;++i){
        if ((i-1)%k==0) temp=0;
        temp=max(temp,arr[i]);
        pre[i]=temp;
    }
    temp=0;
    for (int i=n;i>=1;--i){
        if (i%k==0) temp=0;
        temp=max(temp,arr[i]);
        suf[i]=temp;
    }
    for (int i=1;i<=k;++i) dp[i]=pre[i];
    for (int i=1;i<(n+k-1)/k;++i){
        dp1[i*k]=dp[i*k];
        for (int j=i*k-1;j>(i-1)*k;--j){
            dp1[j]=max(dp1[j+1],dp[j]+suf[j+1]);
            dp[j]=max(dp[j],dp[j+1]);
        }
        for (int j=i*k+1;j<=(i+1)*k;++j){
            dp[j]=max(dp1[j-k],dp[j-k]+pre[j]);
        }
    }
    cout << dp[n] << '\n';
}