#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

struct Area{ ll l, w; } a[MAXN];
ll ans;
multiset<ll> s;

bool cmp(Area a, Area b){ return a.l < b.l; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i].l >> a[i].w;
        if (a[i].w<a[i].l) swap(a[i].w,a[i].l);
        ans=max(a[i].l*a[i].w,ans);
    }
    sort(a+1,a+1+n,cmp); reverse(a+1,a+1+n);
    for (int i=1;i<=n;++i){
        s.insert(a[i].w);
        if (s.size()>=2){
            auto it=--(--s.end());
            ans=max(2*(*it)*a[i].l,ans);
        }
    }
    cout << ans/2;
    if (ans%2==0) cout << ".0" << '\n';
    else cout << ".5" << '\n';

}