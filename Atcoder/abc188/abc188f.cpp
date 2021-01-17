#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

ll x, y;
unordered_map<ll,ll> m;

ll solve(ll n){
    if (m.count(n)) return m[n];
    ll ret=abs(x-n);
    if (n%2==0) ret=min(ret,solve(n/2)+1);
    else if (n!=1) ret=min({ret,solve(n/2)+2,solve(n/2+1)+2});
    return m[n]=ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> x >> y;
    cout << solve(y) << '\n';
}