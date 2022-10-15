#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define lc(v) st[v].vl,st[v].l,st[v].m
#define rc(v) st[v].vr,st[v].m+1,st[v].r
typedef long long ll;
const int seed=131, MAXN=1e5+1;

int n, mod, arr[MAXN];
struct nd{
    ll v, prod, inc;
    int l, r, m, vl, vr;
    void upd(ll a, ll b){ prod=prod*a%mod, inc=(inc*a+b)%mod; }
    ll push();
} st[2*MAXN];

ll nd::push(){
    if (l!=r) st[vl].upd(prod,inc), st[vr].upd(prod,inc);
    return v=(v*prod+(r-l+1)*inc)%mod, prod=1, inc=0, v;
}

ll build(int v=1, int l=1, int r=n){
    int m=l+r>>1; st[v]={0,1,0,l,r,m,v+1,v+2*(m-l+1)};
    if (l==r) return st[v].v=arr[l];
    return st[v].v=(build(lc(v))+build(rc(v)))%mod;
}

ll go(int l, int r, bool qry=1, ll a=1, ll b=0, int v=1){
    if (st[v].push(),st[v].l>r||st[v].r<l) return (qry?0:st[v].v);
    if (st[v].l>=l&&st[v].r<=r) return st[v].upd(a,b), st[v].push();
    ll ret=(go(l,r,qry,a,b,st[v].vl)+go(l,r,qry,a,b,st[v].vr))%mod;
    return (qry?ret:st[v].v=ret);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> mod;
    for (int i=1;i<=n;++i) cin >> arr[i];
    build();
    int q; cin >> q;
    while (q--){
        int op, l, r, x; cin >> op >> l >> r;
        if (op==1) cin >> x, go(l,r,0,x);
        if (op==2) cin >> x, go(l,r,0,1,x);
        if (op==3) cout << go(l,r) << '\n';
    }
}