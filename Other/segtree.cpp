#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
typedef long long ll;
const int mod=1e9+7, inf=INT_MAX, MAXN=1e5;

struct nd{
    nd *lc=0, *rc=0;
    int l, r, val=0, lz=0;
    nd(int _l, int _r) : l(_l), r(_r) {}
    nd(nd* _lc, nd* _rc) : lc(_lc), rc(_rc), l(_lc->l), r(_rc->r), val(min(_lc->val,_rc->val)) {}
    void extend(){ if (!lc) lc=new nd(l,mid), rc=new nd(mid+1,r); }
    nd* clone(){ nd *c=new nd(l,r); c->lc=lc, c->rc=rc, c->val=val, c->lz=lz; return c; }
    void push(){
        if (!lz) return;
        val+=lz;
        if (l!=r){
            lc=lc->clone(), rc=rc->clone();
            lc->lz+=lz, rc->lz+=lz;
        }
        lz=0;
    }
    nd* upd(int ql, int qr, int v){
        extend(); push();
        if (l>qr||r<ql) return this;
        if (l>=ql&&r<=qr){ nd* ret=clone(); ret->lz+=v; ret->push(); return ret;}
        return new nd(lc->upd(ql,qr,v),rc->upd(ql,qr,v));
    }
}; vector<nd*> rts;
int T, a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    rts.push_back(new nd(0,n-1));
    for (int i=0;i<n;++i){
        cin >> a[i];
        rts.push_back(rts.back()->upd(i,i,a[i]));
    }
    while (m--){
        int op, l, r; cin >> op >> l >> r;
        if (op==2){
            r--;
            rts.push_back(rts.back()->upd(l,r,-inf));
            cout << rts.back()->val+inf << '\n';
            rts.pop_back();
        }
        if (op==1){
            rts.push_back(rts.back()->upd(l,l,r-a[l]));
            a[l]=r;
        }
    }
}