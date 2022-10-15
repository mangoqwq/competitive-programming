#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int deg[MAXN], a[MAXN], b[MAXN], ans[MAXN], best;
vector<int> rem;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=0;i<m;++i) cin >> a[i] >> b[i];
    for (int i=0;i<(1<<m);++i){
        ms(deg,0);
        for (int j=0;j<m;++j) if (1&(i>>j)) deg[a[j]]++, deg[b[j]]++;
        for (int j=1;j<=n;++j) ans[i]+=deg[j]%2;
        if (ans[i]>ans[best]) best=i;
    }
    cout << ans[best] << '\n' << m-__builtin_popcount(best) << '\n';
    for (int j=0;j<m;++j) if (!(1&(best>>j))) cout << j+1 << " ";
}