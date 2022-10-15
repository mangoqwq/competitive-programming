#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e7+5;

ll a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int x, y; cin >> x >> y;
    int q; cin >> q;
    for (int i=1;i<=q;++i){
        int l, r; cin >> l >> r;
        a[l]++, a[r+1]--;
    }
    for (int i=1;i<=n;++i) a[i]+=a[i-1];
    cout << accumulate(a+x,a+1+y,0LL) << '\n';
}