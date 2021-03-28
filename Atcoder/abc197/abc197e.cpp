#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+2;

ll dp[MAXN][2];
ll mn[MAXN], mx[MAXN];
bool has[MAXN];

ll walk(ll x, ll i, bool dir){
    if (dir==0){
        return abs(mx[i]-x)+abs(mx[i]-mn[i]);
    }
    else{
        return abs(mn[i]-x)+abs(mx[i]-mn[i]);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        ll x, c; cin >> x >> c;
        if (!has[c]){
            mn[c]=mx[c]=x;
            has[c]=1;
        }
        else{
            mn[c]=min(mn[c],x);
            mx[c]=max(mx[c],x);
        }
    }
    has[n+1]=1;
    for (int i=1;i<=n+1;++i){
        if (!has[i]){
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            mn[i]=mn[i-1];
            mx[i]=mx[i-1];
        }
        else{
            dp[i][0]=min(dp[i-1][0]+walk(mn[i-1],i,0),dp[i-1][1]+walk(mx[i-1],i,0));
            dp[i][1]=min(dp[i-1][0]+walk(mn[i-1],i,1),dp[i-1][1]+walk(mx[i-1],i,1));
        }
    }
    cout << dp[n+1][0] << '\n';
}