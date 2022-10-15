#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

int a[MAXN], b;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int tot=0;
    for (int i=1;i<=n;++i) cin >> a[i], tot+=a[i];
    if (tot<=0) return cout << 0 << '\n', 0;
    for (int i=1;i<=m;++i){
        cin >> b;
        if (a[b]==1) tot-=2;
        else tot;
        a[b]^=1;
        if (tot<=0) return cout << i << '\n', 0;
    }
    cout << m+tot << '\n';
}