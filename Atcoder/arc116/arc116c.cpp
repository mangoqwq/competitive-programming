#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=998244353, inf=0x3f3f3f3f, MAXN=4e5+1;

ll fact[MAXN], inv[MAXN], ans, curr;
vector<ll> cnt;

ll fpow(ll b, ll e){
    ll ret=1;
    while (e){
        if (1&e) ret=ret*b%mod;
        b=b*b%mod, e>>=1;
    }
    return ret;
}

ll choose(ll n, ll k){ return fact[n]*inv[k]%mod*inv[n-k]%mod; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m; cin >> n >> m;
    fact[0]=inv[0]=1;
    for (int i=1;i<MAXN;++i){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=fpow(fact[i],mod-2);
    }
    ans=1;
    for (int i=2;i<=m;++i){
        cnt.clear();
        ll val=i;
        for (ll j=2;j*j<=val;++j){
            if (val%j) continue;
            int uwu=0;
            while (val%j==0) val/=j, uwu++;
            cnt.push_back(uwu);
        }
        if (val!=1) cnt.push_back(1);
        curr=1;
        for (ll x:cnt) curr=(curr*choose(n-1+x,x))%mod;
        ans=(ans+curr)%mod;
    }
    cout << ans << '\n';
}