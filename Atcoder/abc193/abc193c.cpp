#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    ll ans=n;
    for (ll i=2;i*i<=n;++i){
        bool flag=1;
        for (ll j=2;j*j<=i;++j){
            if (i%j) continue;
            ll tmp=i;
            while (tmp%j==0) tmp/=j;
            if (tmp==1) flag=0;
        }
        if (!flag) continue;
        ll tmp=i;
        while (tmp*i<=n){
            tmp*=i, ans--;
        }
    }
    cout << ans << '\n';
}