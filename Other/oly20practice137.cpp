#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

ll ans[MAXN];
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
    int n, k, l, r; cin >> n >> k >> l >> r;
    for (int i=r-l+1;i>=k;--i){
        ans[i]=fpow(r/i-(l-1)/i,n); 
        for (int j=2*i;j<=r-l+1;j+=i) ans[i]-=ans[j];
        ans[i]-=r/i-max({l-1,r-l})/i;
    }
    cout << (ans[k]%mod+mod)%mod << '\n'; 
}