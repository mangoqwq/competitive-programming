#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=10000, inf=0x3f3f3f3f, MAXN=0;

ll fpow(ll b, ll e){
    ll ret=1;
    while (e){
        if (e&1) ret=ret*b%mod;
        b=b*b%mod; e>>=1;
    }
    return ret;
}

ll f(ll x){
    ll ret=0, curr=1;
    for (int i=1;curr<=x;++i){
        ret+=(min(curr*10-1,x)-curr+1)*(i+1); ret%=mod;
        curr*=10;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    ll ans=0;
    ans+=n;
    ans+=2*(n-1);
    ans+=fpow(2,n)-n-1;
    ans+=f(n)-1;
    ans+=fpow(2,n-1)*f(n);
    ans%=mod;
    cout << ans << '\n';
}
