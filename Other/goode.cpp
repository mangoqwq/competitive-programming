#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+1;

int n, q, m;
struct nd{
    int l, r, mid, val;
    bool lz;
} st[2*MAXN];

inline int aa(int v){ return v+2*(st[v].mid-st[v].l+1); }

inline void push(int v){
    if (!st[v].lz) return;
    st[v].lz=0; st[v].val=st[v].r-st[v].l+1-st[v].val;
    if (st[v].l!=st[v].r) st[v+1].lz^=1, st[aa(v)].lz^=1;
}

inline int build(int v=1, int l=1, int r=n){
    int mid=l+r>>1;
    st[v].l=l, st[v].r=r, st[v].mid=mid; st[v].lz=0;
    if (l==r) return st[v].val=1;
    return st[v].val=build(v+1,l,mid)+build(aa(v),mid+1,r);
}

inline void upd(int l, int r, int v=1){
    push(v);
    if (st[v].r<l||st[v].l>r) return;
    if (st[v].l>=l&&st[v].r<=r) st[v].lz^=1, push(v);
    else upd(l,r,v+1), upd(l,r,aa(v)), st[v].val=st[v+1].val+st[aa(v)].val;
}

inline int get(int v=1, int idx=m){
    push(v);
    if (st[v].l==st[v].r) return st[v].l;
    return push(v+1), (st[v+1].val>=idx?get(v+1,idx):get(aa(v),idx-st[v+1].val));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q >> m;
    build();
    while (q--){
        int l, r; cin >> l >> r;
        upd(l,r);
        if (st[1].val<m) cout << "AC?" << '\n';
        else cout << get() << '\n';
    }
}