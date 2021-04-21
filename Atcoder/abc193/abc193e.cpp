#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int inf=0x3f3f3f3f, MAXN=0;

ll egcd(ll a, ll b, ll &x, ll &y){
    if (b==0) return x=1, y=0, a;
    ll x1, y1, g=egcd(b,a%b,x1,y1);
    return x=y1, y=x1-a/b*y1, g;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll X, Y, P, Q; cin >> X >> Y >> P >> Q;
        ll ans=LLONG_MAX;
        for (ll y=X;y<X+Y;++y){
            for (ll q=P;q<P+Q;++q){
                ll mod=(2*X+2*Y);
                ll a, b, g=egcd(P+Q,mod,a,b);
                if ((y-q)%g!=0) continue;
                a=(a*(y-q)/g%mod+mod)%mod;
                ans=min(ans,(a*(P+Q)+q)%(mod*(P+Q)/g));
            }
        }
        if (ans==LLONG_MAX) cout << "infinity" << '\n';
        else cout << ans << '\n';
    }
}