#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5001;

ll dp[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    ms(dp,0x3f);
    dp[0]=0;
    int n; cin >> n;
    int total=0;
    for (int i=0,v,p;i<n;++i){
        cin >> v >> p;
        total+=p;
        v=(v/2)+1;
        for (int i=MAXN;i>=p;--i) dp[i]=min(dp[i],dp[i-p]+v);
    }
    ll ans=LLONG_MAX;
    for (int i=(total/2)+1;i<=total;++i){
        ans=min(ans,dp[i]);
    }
    cout << ans << '\n';
}