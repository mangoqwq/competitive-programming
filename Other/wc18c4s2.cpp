#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3005;

int n; ll m, dp[MAXN];
struct Tree{
    ll idx, w;
    bool operator<(const Tree &x) const{
        return idx<x.idx;
    }
} arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1;i<=n;++i) cin >> arr[i].idx >> arr[i].w;
    dp[0]=0; arr[++n]={m,0};
    sort(arr,arr+1+n);
    ms(dp,0x3f), dp[0]=0;
    for (int i=1;i<=n;++i){
        ll worst=0;
        for (int j=i;j>=1;--j){
            worst=max(worst,arr[j].w);
            dp[i]=min(dp[i],dp[j-1]-arr[j-1].idx+max(worst,(arr[i].idx-arr[j].idx)*2)+arr[i].idx);
        }
    }
    cout << dp[n] << '\n';
}