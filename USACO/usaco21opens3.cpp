#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

ll c[MAXN], cnt[MAXN], add;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, k, l; cin >> n >> k >> l;
    l=k*l;
    for (int i=1;i<=n;++i) cin >> c[i];
    sort(c+1,c+1+n,greater<ll>());
    for (int i=1;i<=n;++i){
        l-=add;
        add+=cnt[i];
        if (c[i]>i) cnt[c[i]]++;
        else l-=i-c[i], add++;
        if (l<0||i-c[i]>k) return cout << i-1 << '\n', 0;
    }
    cout << n << '\n';
}