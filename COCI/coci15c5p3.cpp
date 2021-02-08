#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

ll fact[MAXN], inv[MAXN], ans;
int a[MAXN];

ll fpow(ll b, ll e){
    ll ans=1;
    while (e){
        if (e&1) ans=ans*b%mod;
        e>>=1; b=b*b%mod;
    }
    return ans;
}

ll choose(ll n, ll r){ return fact[n]*inv[r]%mod*inv[n-r]%mod; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    fact[0]=inv[0]=1;
    for (int i=1;i<=n;++i) fact[i]=fact[i-1]*i%mod, inv[i]=fpow(fact[i],mod-2);
    for (int i=1;i<=n;++i) cin >> a[i];
    sort(a+1,a+1+n);
    for (int i=k;i<=n;++i){
        ans+=choose(i-1,k-1)*a[i];
        ans%=mod;
    }
    cout << ans << '\n';
}