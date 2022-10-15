#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1'000'001;

ll dp[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    ms(dp,0x3f); 
    dp[0]=0;
    int n,m; cin >> n >> m;
    for (int i=0,v,w;i<n;++i){
        cin >> v >> w;
        for (int k=v;k<MAXN;++k){
            dp[k]=min(dp[k],dp[k-v]+w);
        }
    }
    ll ans=0x3f3f3f3f3f3f3f3f;
    for (int i=m;i<MAXN;++i){
        ans=min(ans,dp[i]);
    }
    cout << ans << '\n';
}