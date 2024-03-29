#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;
const double pi=3.14159265358979323846;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n; cin >> n;
        if (n<=1e5){
            ll ans=0;
            for (ll k=1;k<=n;++k){
                ans+=sqrt(n*n-k*k);
            }
            cout << ans << '\n';
        }
        else{
            cout << pi*n*n/4 << '\n';
        }
    }
}