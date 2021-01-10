#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

ll ans[MAXN], tot;

ll fpow(ll b, ll e){
    ll ret=1;
    while (e){
        if (e&1) ret=ret*b%mod;
        e>>=1, b=b*b%mod;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i=k;i>=1;--i){
        ans[i]=fpow(k/i,n);
        for (int j=2*i;j<=k;j+=i) ans[i]=(ans[i]-ans[j]+mod)%mod;
    }
    for (int i=1;i<=k;++i) tot=(tot+i*ans[i])%mod;
    cout << tot << '\n';
}