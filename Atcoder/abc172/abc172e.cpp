#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5e5+1;

ll fact[MAXN], inv[MAXN];

ll fpow(ll b, ll e){
    ll ans=1;
    while (e){
        if (e&1) ans=ans*b%mod;
        b=b*b%mod, e>>=1;
    }
    return ans;
}

ll choose(int n, int k){ return fact[n]*inv[k]%mod*inv[n-k]%mod; }
ll permu(int n, int k){ return fact[n]*inv[n-k]%mod; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fact[0]=1, inv[0]=1;
    for (int i=1;i<MAXN;++i) fact[i]=fact[i-1]*i%mod, inv[i]=fpow(fact[i],mod-2);
    int n, m; cin >> n >> m;
    ll tot=0;
    for (int i=1;i<=n;++i){
        tot+=(i%2?1:-1)*choose(n,i)*permu(m-i,n-i)%mod;
        tot=(tot+mod)%mod;
    }
    tot=(permu(m,n)-tot+mod)%mod;
    tot=tot*permu(m,n)%mod;
    cout << tot << '\n';
}