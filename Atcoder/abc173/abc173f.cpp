#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll ans=0;
    for (ll i=1;i<=n;++i) ans+=i*(n-i+1);
    for (int i=1;i<=n-1;++i){
        ll a, b; cin >> a >> b;
        if (b<a) swap(a,b);
        ans-=a*(n-b+1);
    }
    cout << ans << '\n';
}