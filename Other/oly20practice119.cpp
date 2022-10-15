#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

ll fpow(ll x, ll e){
    ll ans=1;
    while (e){
        if (e&1) ans*=x, ans%=mod;
        x*=x; x%=mod;
        e>>=1;
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll a1, a2, a3, k;
        cin >> a1 >> a2 >> a3 >> k;
        if (a3-a2==a2-a1){
            cout << (a1+(a2-a1)*(k-1))%mod << '\n';
        }
        else{
            cout << ((ll)a1*fpow(a2/a1, k-1))%mod << '\n';
        }
    }
}