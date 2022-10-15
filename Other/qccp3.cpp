#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=998244353, inf=0x3f3f3f3f, MAXN=1e6+1;

ll fact[MAXN], inv[MAXN];

ll fpow(ll b, ll e){
    ll ret=1;
    while (e){
        if (1&e) ret=ret*b%mod;
        b=b*b%mod, e>>=1;
    }
    return ret;
}

ll choose(int n, int k){ return fact[n]*inv[k]%mod*inv[n-k]%mod; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fact[0]=inv[0]=1;
    for (int i=1;i<MAXN;++i){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=fpow(fact[i],mod-2);
    }
    int t; cin >> t;
    while (t--){
        ll n, k, q; cin >> n >> k >> q;
        ll a=n-q*k-(q-1);
        ll b=q+1;
        if (a<0) cout << 0 << '\n';
        else{
            cout << choose(a+b-1,b-1) << '\n';
        }
    }
}