#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

mt19937 gen;
uniform_int_distribution<int> dis(1,1e9);

struct nd{
    ll p, v, sz, tot, inc, flag, set;
    nd *l, *r;
    nd(ll _v) : p(dis(gen)), v(_v), sz(1), tot(_v), inc(0),
                flag(0), set(0),  l(0), r(0) {}
};

namespace Treap{
    ll get_sz(nd *t){ return t?t->sz:0; }
    ll get_tot(nd *t){ return t?t->tot:0; }
    void push(nd *t){
        if (!t) return;
        if (t->flag){
            t->v=t->set;
            t->tot=t->sz*t->set;
            if (t->l){
                t->l->inc=0;
                t->l->flag=1;
                t->l->set=t->set;
            }
            if (t->r){
                t->r->inc=0;
                t->r->flag=1;
                t->r->set=t->set;
            }
            t->set=t->flag=0;
        }
        if (t->inc){
            t->v+=t->inc;
            t->tot+=t->sz*t->inc;
            if (t->l) t->l->inc+=t->inc;
            if (t->r) t->r->inc+=t->inc;
            t->inc=0;
        }
    }
    void pull(nd *t){
        if (!t) return;
        push(t->l), push(t->r);
        t->sz=1+get_sz(t->l)+get_sz(t->r);
        t->tot=t->v+get_tot(t->l)+get_tot(t->r);
    }
    void splitkey(nd *t, nd *&l, nd *&r, ll v){
        push(t);
        if (!t) l=r=0;
        else if (t->v<=v) splitkey(t->r,t->r,r,v), l=t;
        else splitkey(t->l,l,t->l,v), r=t;
        pull(t);
    }
    void splitidx(nd *t, nd *&l, nd *&r, int cnt){
        assert(cnt<=get_sz(t));
        push(t);
        if (!t) l=r=0;
        else if (get_sz(t->l)+1<=cnt) splitidx(t->r,t->r,r,cnt-get_sz(t->l)-1), l=t;
        else splitidx(t->l,l,t->l,cnt), r=t;
        pull(t);
    }
    void merge(nd *&t, nd *l, nd *r){
        push(l), push(r);
        if (!l||!r) t=l?l:r;
        else if (l->p>r->p) merge(l->r,l->r,r), t=l;
        else merge(r->l,l,r->l), t=r;
        pull(t);
    }
    void insert(nd *&t, ll v){
        nd *t1, *t2, *it=new nd(v);
        splitkey(t,t1,t2,v);
        merge(t,t1,it), merge(t,t,t2);
    }
    void inc(nd *t, ll v){ if (t) t->inc+=v; }
    void set(nd *t, ll v){ if (t) t->inc=0, t->set=v, t->flag=1; }
    void print(nd *t){
        if (!t) return;
        print(t->l);
        cout << t->v << " ";
        print(t->r);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    nd *rt=0;
    int n; ll k; cin >> n >> k;
    for (int i=1;i<=n;++i){
        int v; cin >> v; v--;
        nd *l, *r;
        Treap::splitidx(rt,l,r,v);
        ll price=Treap::get_tot(l)+Treap::get_sz(l);
        if (price>k){ // throw him overboard!!! 
            cout << -1 << '\n';
            Treap::merge(rt,l,r);
            Treap::insert(rt,-1);
        }
        else{
            cout << k-price << '\n';
            Treap::inc(l,1);
            Treap::set(r,0);
            Treap::merge(rt,r,l);
            Treap::insert(rt,k-price);
        }

    }
}
