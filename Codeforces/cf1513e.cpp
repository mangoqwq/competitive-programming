#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+5;

ll a[MAXN], fact[MAXN], tot;

ll fpow(ll b, ll e){
    ll ret=1;
    while (e){
        if (1&e) ret=ret*b%mod;
        b=b*b%mod, e>>=1;
    }
    return ret;
}
ll inv(ll x){ return fpow(x,mod-2); }
ll choose(ll n, ll k){ return fact[n]*inv(fact[k])%mod*inv(fact[n-k])%mod; }
map<ll,int> lo, mid, hi;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fact[0]=1;
    for (int i=1;i<MAXN;++i) fact[i]=fact[i-1]*i%mod;
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    tot=accumulate(a+1,a+1+n,0LL);
    if (tot%n) return cout << 0 << '\n', 0;
    tot/=n;
    for (int i=1;i<=n;++i){
        if (a[i]<tot) lo[a[i]]++;
        if (a[i]==tot) mid[a[i]]++;
        if (a[i]>tot) hi[a[i]]++;
    }
    if ((lo.size()==1&&lo.begin()->second==1)||(hi.size()==1&&hi.begin()->second==1)){
        ll ans=fact[n];
        for (auto x:lo) ans=ans*inv(fact[x.second])%mod;
        for (auto x:mid) ans=ans*inv(fact[x.second])%mod;
        for (auto x:hi) ans=ans*inv(fact[x.second])%mod;
        cout << ans << '\n';
        return 0;
    }
    ll lhs=0, rhs=0;
    for (auto x:lo) lhs+=x.second;
    lhs=fact[lhs];
    for (auto x:lo) lhs=lhs*inv(fact[x.second])%mod;
    for (auto x:hi) rhs+=x.second;
    rhs=fact[rhs];
    for (auto x:hi) rhs=rhs*inv(fact[x.second])%mod;
    ll ans=lhs*rhs%mod;
    ll na=mid.begin()->second;
    ans=ans*choose(n,na)%mod;
    if (!hi.empty()) ans=ans*2%mod;
    cout << ans << '\n';
}