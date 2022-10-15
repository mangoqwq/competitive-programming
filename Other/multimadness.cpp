#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

ll fact[MAXN], inv[MAXN];

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
    fact[0]=inv[0]=1;
    for (int i=1;i<MAXN;++i){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=fpow(fact[i],mod-2);
    }
    int n; cin >> n;
    while (n--){
        int l, r; cin >> l >> r;
        if (l==0) cout << 0 << '\n';
        else cout << fact[r]*inv[l-1]%mod << '\n';
    }
}