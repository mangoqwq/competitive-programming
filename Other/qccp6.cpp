#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

ll h[MAXN], ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll curr=0, tmp=0;
    for (int i=1;i<=n;++i) cin >> h[i], tmp+=abs(h[i]-h[i-1]), curr+=tmp;
    for (int i=1;i<=n;++i){
        curr+=abs(h[i]-h[i-1])*((i-1)-(n-i+1));
        ans[i]=curr;
    }
    int q; cin >> q;
    while (q--){
        int x; cin >> x;
        cout << ans[x] << '\n';
    }
}