#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int x[MAXN], y[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> x[i];
    for (int i=1;i<=n;++i) cin >> y[i];
    int mxx=*max_element(x+1,x+1+n), mnx=*min_element(x+1,x+1+n);
    int mxy=*max_element(y+1,y+1+n), mny=*min_element(y+1,y+1+n);
    int q; cin >> q;
    while (q--){
        int op, i; cin >> op >> i;
        if (op==1) cout << max(mxy,x[i]) << '\n';
        if (op==2) cout << max(mny,x[i]) << '\n';
        if (op==3) cout << max(mxx,y[i]) << '\n';
        if (op==4) cout << max(mnx,y[i]) << '\n';
    }
}