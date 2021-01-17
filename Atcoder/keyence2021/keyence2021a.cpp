#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

int a[MAXN], b[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i], a[i]=max(a[i],a[i-1]);
    for (int i=1;i<=n;++i) cin >> b[i];
    ll best=0;
    for (int i=1;i<=n;++i) best=max(best,1LL*a[i]*b[i]), cout << best << '\n';
}