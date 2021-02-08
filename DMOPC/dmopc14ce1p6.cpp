#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3001;

ll fact[MAXN], inv[MAXN], p2[MAXN];

ll fpow(ll b, ll e){
    ll ans=1;
    while (e){
        if (1&e) ans=ans*b%mod;
        b=b*b%mod, e>>=1;
    }
    return ans;
}

ll choose(ll n, ll r){ return fact[n]*inv[r]%mod*inv[n-r]%mod; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fact[0]=inv[0]=p2[0]=1;
    for (int i=1;i<MAXN;++i){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=fpow(fact[i],mod-2);
        p2[i]=p2[i-1]*2%mod;
    }
    int t; cin >> t;
    while (t--){
        int r, c; cin >> r >> c;
        ll ans=0;
        for (int i=0;i<c;++i){
            ans+=(i%2?-1:1)*choose(c,c-i)*fpow(p2[c-i]-1,r)%mod;
            ans=(ans+mod)%mod;
        }
        cout << ans << '\n';
    }
}