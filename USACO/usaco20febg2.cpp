#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+5;

int l[MAXN], r[MAXN], pow2[MAXN], psa[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    pow2[0]=1;
    for (int i=1;i<=n;++i) pow2[i]=pow2[i-1]*2%mod;
    ll ans=0;
    for (int i=1;i<=n;++i){
        cin >> l[i] >> r[i];
        psa[l[i]]++, psa[r[i]]--;
    }
    for (int i=1;i<=MAXN;++i) psa[i]+=psa[i-1];
    for (int i=1;i<=n;++i) ans+=pow2[n-1-psa[l[i]-1]], ans%=mod;
    cout << ans << '\n';
}