#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=2e9, MAXN=1e5+1;

ll n, c;
ll s[MAXN], w[MAXN];

bool check(ll L, ll R){
    ll l=0, r=0;
    for (ll i=1;i<=n;++i){
        ll v=s[i];
        l+=w[i], r+=w[i];
        if (i==n){
            if (!(v+l>R||v+r<L)) return 1;
            else return 0;
        }
        if (v<L){
            ll diff=L-v;
            v+=diff;
            l-=diff; r-=diff;
            if (r<0) return 0;
            l=max(l,0LL);
        }
        if (r>c){
            ll diff=max(l-c,0LL);
            v+=diff;
            l-=diff;
            r=c;
        }        
        if (v>R) return 0;
        ll diff=min(R-v,l);
        l-=diff;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> c;
    for (ll i=1;i<=n;++i) cin >> s[i] >> w[i];
    ll l=0, r=2e9, mid;
    ll mn, mx;
    while (l<r){
        mid=l+r+1>>1;
        if (check(mid,inf)) l=mid;
        else r=mid-1;
    }
    mn=l;
    l=0, r=2e9;
    while (l<r){
        mid=l+r>>1;
        if (check(0,mid)) r=mid;
        else l=mid+1;
    }
    mx=l;
    cout << mx-mn << '\n';
}