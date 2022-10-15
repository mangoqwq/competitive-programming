#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int n, p;
ll fact[MAXN], inv[MAXN];
int sieve[MAXN];

void init(){
    for (ll i=2;i<MAXN;++i){
        if (sieve[i]) continue;
        sieve[i]=i;
        for (ll j=i*i;j<MAXN;j+=i){
            sieve[j]=i;
        }
    }
}
ll fpow(ll b, ll e, ll m=mod){
    ll ret=1;
    while (e){
        if (1&e) ret=ret*b%m;
        b=b*b%m, e>>=1;
    }
    return ret;
}
ll choose(ll n, ll k){
    if (n<k) return 0;
    else return fact[n]*inv[k]%p*inv[n-k]%p;
}
ll lucas(ll n, ll k){
    ll ret=1;
    while (n){
        int ni=n%p; n/=p;
        int ki=k%p; k/=p;
        ret=ret*choose(ni,ki)%p;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> p;
    if (n==1){
        int x; cin >> x;
        cout << x << '\n';
        return 0;
    }
    init();
    fact[0]=1; inv[0]=1;
    for (int i=1;i<p;++i){
        fact[i]=fact[i-1]*i%p;
        inv[i]=fpow(fact[i],p-2,p);
    }
    map<ll,ll> pf;
    for (int i=0;i<n;++i){
        int a; cin >> a;
        int coeff=lucas(n-1,i);
        for (int i=a;sieve[i];i/=sieve[i]){
            pf[sieve[i]]+=coeff;
        }
    }
    ll ans=1;
    for (auto &[a,b]:pf){
        b%=p;
        ans=ans*fpow(a,b)%mod;
    }
    cout << ans << '\n';
}