#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

ll a[MAXN], b[MAXN];

ll calc(ll target, ll curr, ll wage){
    return max(0LL,(target-curr+wage-1)/wage);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ll n, c; cin >> n >> c;
        ll ans=LLONG_MAX, day=0, val=0;
        for (int i=1;i<=n;++i) cin >> a[i];
        for (int i=1;i<=n-1;++i) cin >> b[i];
        for (int i=1;i<=n;++i){
            ans=min(ans,day+calc(c,val,a[i]));
            if (i==n) break;
            ll tmp=calc(b[i],val,a[i]);
            day+=tmp+1; val=val+tmp*a[i]-b[i];
        }
        cout << ans << '\n';
    }
}