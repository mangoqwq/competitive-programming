#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1, V=1e5;

int dp[MAXN], ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m; cin >> n >> m;
    ms(ans,inf); ms(dp,0x3f); dp[0]=0;
    for (int day=1;day<=n;++day){
        ll op, p, t; cin >> op >> p >> t;
        if (op==1){
            p=(V-1+p)/V;
            for (int i=p;i<=m;++i){
                if (dp[i-p]!=inf&&dp[i-p]!=t) dp[i]=min(dp[i],dp[i-p]+1);
            }
        }
        if (op==2){
            for (ll i=0;i<=m;++i){
                ll nxt=(V-1+(p*i))/V;
                if (nxt>m) continue;
                if (dp[i]!=inf&&dp[i]!=t) dp[nxt]=min(dp[nxt],dp[i]+1);
            }
        }
        for (int i=1;i<=m;++i){
            if (dp[i]==inf) continue;
            ans[i]=min(ans[i],day);
            dp[i]=0;
        }
    }
    for (int i=1;i<=m;++i) cout << (ans[i]==inf?-1:ans[i]) << " ";
}

// -1 -1 -1 1 -1 -1 -1 1 -1 -1 3 -1 -1 -1 3 -1 2 -1 3 -1 
// -1 -1 -1 1 -1 -1 -1 1 -1 -1 3 -1 -1 -1 3 -1 2 -1 3 -1