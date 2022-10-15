#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

ll l[MAXN], r[MAXN], ans;

int main(){
    int n, L; cin >> n >> L;
    for (int i=1;i<=n;++i) cin >> l[i] >> r[i], ans+=abs(r[i]-l[i]);
    l[0]=L, r[0]=0;
    sort(l,l+1+n), sort(r,r+1+n);
    for (int i=0;i<=n;++i) ans+=abs(r[i]-l[i]);
    cout << ans << '\n';
}