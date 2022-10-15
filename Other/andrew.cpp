#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+5;

ll p2[MAXN], fact[MAXN], inv[MAXN];

ll fpow(ll b, ll e){
    ll ans=1;
    while (e){
        if (1&e) ans=ans*b%mod;
        b=b*b%mod, e>>=1;
    }
    return ans;
}

ll choose(ll n, ll k){ return fact[n]*inv[k]%mod*inv[n-k]%mod; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    p2[0]=fact[0]=inv[0]=1;    
    for (int i=1;i<MAXN;++i){
        p2[i]=p2[i-1]*2%mod;
        fact[i]=fact[i-1]*i%mod;
        inv[i]=fpow(fact[i],mod-2);
    }
    ll n, d; cin >> n >> d;
    ll tot=n-d, ans=0;
    for (int i=1;i<=tot;++i){
        ll curr=p2[i]*fact[n-i]%mod*choose(tot,i)%mod;
        if (i%2==0) ans=(ans-curr+mod)%mod;
        else ans=(ans+curr)%mod;
    }
    cout << ans << '\n';
}