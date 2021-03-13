#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e4+7, inf=0x3f3f3f3f, MAXN=53;

int fact[MAXN], p2[MAXN], inv[MAXN];

int fpow(int b, int e){
    int ret=1;
    while (e){
        if (e&1) ret=ret*b%mod;
        b=b*b%mod, e>>=1;
    }
    return ret;
}

int choose(int n, int k){
    if (k>n) return 0;
    return fact[n]*inv[k]%mod*inv[n-k]%mod;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fact[0]=inv[0]=p2[0]=1;
    for (int i=1;i<=52;++i){
        fact[i]=fact[i-1]*i%mod;
        inv[i]=fpow(fact[i],mod-2);
        p2[i]=p2[i-1]*2%mod;
    }
    int n; cin >> n;
    int ans=0;
    for (int i=1;i*4<=n;++i){
        ans+=(i%2?1:-1)*choose(13,i)*choose(52-4*i,n-4*i)%mod;
        ans=(ans+mod)%mod;
    }
    cout << ans << '\n';
}