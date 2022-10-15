#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+1;

ll get(ll x){
    ll y=0;
    for (ll i=2;i*i<=x;++i){
        if (x%i!=0) continue;
        if (i*i==x) y+=i;
        else y+=i, y+=x/i;
    }
    return y+1;
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        ll x; cin >> x;
        int cnt=0;
        while (x<=(ll)1e12&&cnt<1000&&get(x)!=1){
            cnt++;
            x=get(x);
        }
        if (x>(ll)1e12||cnt>=1000) cout << "INFINITY" << '\n';
        else cout << x << " " << cnt << '\n';
    }
}