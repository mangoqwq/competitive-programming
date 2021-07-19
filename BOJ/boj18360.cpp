#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

mt19937 gen;
uniform_int_distribution<int> dis(1,1e9);
struct Treap{
private:
    struct nd{
        ll v, p, sz, tot;
        nd *l, *r;
        nd(ll _v) : v(_v), p(dis(gen)), sz(1), tot(_v), l(0), r(0) {}
    } *rt=0;
    ll getsz(nd *t){ return t?t->sz:0; }
    ll gettot(nd *t){ return t?t->tot:0; }
    void upd(nd *t){
        if (!t) return;
        t->sz=getsz(t->l)+1+getsz(t->r);
        t->tot=gettot(t->l)+t->v+gettot(t->r);
    }
    void split(nd *t, ll v, nd *&l, nd *&r){
        if (!t) return void(l=r=0);
        if (v>=t->v) split(t->r,v,t->r,r), l=t;
        else split(t->l,v,l,t->l), r=t;
        upd(t);
    }
    void merge(nd *&t, nd *l, nd *r){
        if (!l||!r) return void(t=l?l:r);
        if (l->p>r->p) merge(l->r,l->r,r), t=l;
        else merge(r->l,l,r->l), t=r;
        upd(t);
    }
public:
    void ins(int v){
        nd *l, *r;
        split(rt,v,l,r);
        merge(rt,l,new nd(v));
        merge(rt,rt,r);
    }
    void rem(int v){
        nd *l, *m, *r;
        split(rt,v,l,r);
        split(l,v-1,l,m);
        if (m) merge(l,l,m->l), merge(r,m->r,r);
        merge(rt,l,r);
    }
    bool calc(ll c, ll d){
        nd *l, *r;
        split(rt,d,l,r);
        ll val=gettot(l)+getsz(r)*d;
        merge(rt,l,r);
        return val>=c*d;
    }
};
ll v[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    Treap t;
    ms(v,-1);
    while (m--){
        char c; cin >> c;
        if (c=='U'){
            ll i, x; cin >> i >> x;
            if (v[i]!=-1) t.rem(v[i]);
            v[i]=x; t.ins(v[i]);
        }
        if (c=='Z'){
            ll c, d; cin >> c >> d;
            cout << (t.calc(c,d)?"TAK":"NIE") << '\n';
        }
    }
}
