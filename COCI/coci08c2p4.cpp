#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=101, inf=1e9;

ll a[MAXN], b[MAXN], c[MAXN], d[MAXN];

ll get(int coco, int n, ll a1[], ll a2[]){ // find min time
    ll lo=0, hi=inf, mid;
    while (lo<hi){
        mid=lo+hi>>1;
        ll curr=0;
        for (int i=1;i<=n;++i) curr+=(mid>=a1[i]?(mid-a1[i]+a2[i])/a2[i]:0);
        if (curr>=coco) hi=mid;
        else lo=mid+1;
    }
    return lo;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll t, n, m; cin >> t;
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i] >> b[i];
    cin >> m;
    for (int i=1;i<=m;++i) cin >> c[i] >> d[i];
    ll lo=0, hi=inf, mid;
    while (lo<hi){
        mid=lo+hi+1>>1;
        if (get(mid,n,a,b)+get(mid,m,c,d)<=t) lo=mid;
        else hi=mid-1;
    }
    cout << get(lo,n,a,b) << '\n';
}