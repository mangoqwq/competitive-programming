#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e9+1;

map<int,ll> dp; int n;

ll solve(int x){
    if (dp.count(x)) return dp[x];
    ll ans=0;
    for (ll i=1;i*i<=x;++i){
        ans+=solve(i)*(ll)(x/i-x/(i+1));
        if ((x/i)*(x/i)>x && i!=1) ans+=solve(x/i);
    }
    return dp[x]=ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    dp[1]=1;
    cin >> n;
    cout << solve(n) << '\n';
}