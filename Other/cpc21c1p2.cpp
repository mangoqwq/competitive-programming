#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    n=2*n+1;
    map<ll,int> ta, b;
    ll tota=0, totb=0;
    for (int i=1;i<=n;++i){
        ll x; cin >> x;
        tota^=x;
        ta[x]++;
    }
    for (int i=1;i<=n;++i){
        ll x; cin >> x;
        totb^=x;
        b[x]++;
    }
    ll x=tota^totb;
    bool same=1;
    for (auto [val,cnt]:ta){
        if (b[val^x]!=cnt) same=0;
    }
    if (same) cout << x << '\n';
    else cout << -1 << '\n';
}
