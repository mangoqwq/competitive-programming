#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

ll a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> a[i];
    sort(a+1,a+1+n,greater<ll>());
    ll ans=0;
    for (int i=1;i<=k;++i) ans+=a[i];
    cout << ans << '\n';
}