#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=998244353, inf=0x3f3f3f3f, MAXN=1e4+1;

ll n, m, arr[MAXN], cnt[MAXN], fact[MAXN], finv[MAXN];
ll fpow(ll b, ll e){
    ll ans=1;
    while (e){
        if (1&e) ans=ans*b%mod;
        b=b*b%mod, e>>=1;
    }
    return ans;
}
ll inv(ll x){ return fpow(x,mod-2); }
ll choose(ll a, ll b){ return (a>b?0:fact[a]*finv[a-b]%mod*finv[b]%mod); }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    fact[0]=finv[0]=1;
    for (int i=1;i<=m;++i) fact[i]=fact[i-1]*i%mod, finv[i]=inv(fact[i]);
    for (int i=0;i<m;++i) cin >> arr[i];
    
}