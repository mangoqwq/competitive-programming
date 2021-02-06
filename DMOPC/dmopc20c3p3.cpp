#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

ll fpow(ll b, ll e){
    ll ret=1;
    while (e){
        if (1&e) ret=ret*b%mod;
        e>>=1, b=b*b%mod;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    while (q--){
        ll n, m, k, b;
        cin >> n >> m >> k >> b;
        if (n%3==0&&k==1){
            ll tmp=b*b%mod;
            b=fpow(b,3);
            n/=3;
            cout << (tmp*(fpow(b,n)-1)%mod*fpow(b-1,mod-2)%mod*m)%mod << '\n';
        }
        else if (n%2==0&&k==2&&m%2==0){
            ll tmp=b;
            b=fpow(b,2);
            n/=2;
            cout << (tmp*(fpow(b,n)-1)%mod*fpow(b-1,mod-2)%mod*(m/2))%mod << '\n';
        } 
        else if (m%(k+2)==0){
            cout << ((fpow(b,n)-1)*fpow(b-1,mod-2)%mod*((m)/(k+2)))%mod << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
}