#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=4e6+1;

ll fact[MAXN];

ll fpow(ll b, ll e){
    ll ret=1;
    while (e){
        if (1&e) ret=ret*b%mod;
        b=b*b%mod, e>>=1;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fact[0]=1;
    for (int i=1;i<MAXN;++i) fact[i]=fact[i-1]*i%mod;
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        cout << fact[n]*fpow(fact[k],mod-2)%mod*fpow(fact[n-k],mod-2)%mod << '\n';
    }
}