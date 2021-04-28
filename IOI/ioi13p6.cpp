#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

mt19937 gen;
uniform_int_distribution<int> dis(1,1e9);

int rows, cols;
struct nd{
    int y, p; ll v, g;
    nd *l, *r;
    nd(int _y, ll _v) : y(_y), p(dis(gen)), v(_v), g(_v), l(0), r(0) {};
};
namespace Treap{
    ll get(nd *t){ return t?t->g:0; }
    void pull(nd *t){ if (t) t->g=gcd(t->v,gcd(get(t->l),get(t->r))); }
    void print(nd *t){
        if (!t) return;
        if (t->l) print(t->l);
        cout << t->y << " : " << t->v << " | ";
        if (t->r) print(t->r);
    }    
    void split(nd *t, nd *&l, nd *&r, int y){
        if (!t) l=r=0;
        else if (t->y<=y) split(t->r,t->r,r,y), l=t;
        else split(t->l,l,t->l,y), r=t;
        pull(t);
    }
    void merge(nd *&t, nd *l, nd *r){
        if (!l||!r) t=l?l:r;
        else if (l->p>r->p) merge(l->r,l->r,r), t=l;
        else merge(r->l,l,r->l), t=r;
        pull(t);
    }
    void insert(nd *&t, int y, ll v){
        nd *it=new nd(y,v);
        nd *tl, *tmp, *tr;
        split(t,tmp,tr,y), split(tmp,tl,tmp,y-1);
        merge(t,tl,it), merge(t,t,tr);
    }
    ll query(nd *t, int l, int r){
        nd *tl, *tm, *tr;
        split(t,tl,tm,l-1), split(tm,tm,tr,r);
        ll ret=get(tm);
        merge(t,tl,tm), merge(t,t,tr);
        return ret;
    }

};
struct Node2d{
    nd *v;
    int l, r;
    Node2d *lc, *rc;
    Node2d(int nl, int nr) : l(nl), r(nr), lc(0), rc(0), v(0) {}
    void extendl(){ if (!lc&&l!=r) lc=new Node2d(l,mid); }
    void extendr(){ if (!rc&&l!=r) rc=new Node2d(mid+1,r); }
    ll getl(int y){ return lc?Treap::query(lc->v,y,y):0; }
    ll getr(int y){ return rc?Treap::query(rc->v,y,y):0; }
    void upd(int x, int y, ll val){
        if (l==r) return void(Treap::insert(v,y,val));
        if (x<=mid) extendl(), lc->upd(x,y,val);
        else extendr(), rc->upd(x,y,val);
        Treap::insert(v,y,gcd(getl(y),getr(y)));
    }
    ll qry(int xl, int xr, int yl, int yr){
        if (Treap::get(v)==0) return 0;
        if (l>xr||r<xl) return 0;
        if (l>=xl&&r<=xr) return Treap::query(v,yl,yr);
        return gcd(lc?lc->qry(xl,xr,yl,yr):0,rc?rc->qry(xl,xr,yl,yr):0);
    }
} *st;

void init(int R, int C){
    rows=R-1, cols=C-1;
    st=new Node2d(0,rows);
}

void update(int r, int c, ll k){
    st->upd(r,c,k);
}

ll calculate(int r1, int c1, int r2, int c2){
    return st->qry(r1,r2,c1,c2);
}

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    init(2,3);
    update(0,0,20);
    update(0,2,15);
    update(1,1,12);
    cout << calculate(0,0,0,2) << '\n';
    cout << calculate(0,0,1,1) << '\n';
    update(0,1,6);
    update(1,1,14);
    cout << calculate(0,0,0,2) << '\n';
    cout << calculate(0,0,1,1) << '\n';
}

/*
    init(2,3);
    update(0,0,20);
    update(0,2,15);
    update(1,1,12);
    cout << calculate(0,0,0,2) << '\n';
    cout << calculate(0,0,1,1) << '\n';
    update(0,1,6);
    update(1,1,14);
    cout << calculate(0,0,0,2) << '\n';
    cout << calculate(0,0,1,1) << '\n';
*/