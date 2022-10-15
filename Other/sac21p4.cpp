#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

ll a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=n;++i) a[i]+=a[i-1];
    while (q--){
        int l, r; cin >> l >> r;
        ll tot=a[r]-a[l-1];
        cout << tot/(r-l+1) << '\n';
    }
}