#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 0;

mt19937 gen;
uniform_int_distribution<int> dis(1,1e9);

struct Treap{
    struct nd{
        ll p, v, sz, tot, inc, flag, set;
        nd *l, *r;
        nd(ll _v) : p(dis(gen)), v(_v), sz(1), tot(_v), inc(0),
                    flag(0), set(0),  l(0), r(0) {}
    } *rt = 0;
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
    void insert(ll v){
        nd *t1, *t2, *it=new nd(v);
        splitkey(rt,t1,t2,v);
        merge(rt,t1,it), merge(rt,rt,t2);
        // print(rt);
        // cout << '\n';
    }
    void inc(nd *t, ll v){ if (t) t->inc+=v; }
    void set(nd *t, ll v){ if (t) t->inc=0, t->set=v, t->flag=1; }
    void print(nd *t){
        if (!t) return;
        push(t);
        print(t->l);
        cout << t->v << " ";
        print(t->r);
    }
    int getmax(nd *t){
        assert(t);
        if (t->r) return getmax(t->r);
        return t->v;
    }
    int getmin(nd *t){
        assert(t);
        if (t->l) return getmin(t->l);
        return t->v;
    }
    void update_least(int k){
        // print(rt);
        // cout << '\n';
        nd *t1, *t2, *t3, *t4;
        splitidx(rt, t1, t4, k);
        int tmp = getmax(t1);
        inc(t1, 1);
        splitkey(t1, t1, t3, tmp);
        splitkey(t4, t2, t4, tmp);
        merge(rt, t1, t2);
        merge(rt, rt, t3);
        merge(rt, rt, t4);
        // print(rt);
        // cout << '\n';
        // cout << '\n';
    }
    ll calc_ans(nd *t){
        if (!t) return 0;
        push(t);
        ll ret = t->v * (t->v - 1) / 2;
        ret += calc_ans(t->l);
        ret += calc_ans(t->r);
        return ret;
    }
};

struct Mast{
    int h, k;
    bool operator<(const Mast &x) const{
        return h < x.h;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<Mast> a(n);
    for (auto &[h, k] : a){
        cin >> h >> k;
    }
    sort(a.begin(), a.end());
    Treap t;
    int in = 0;
    for (auto &[h, k] : a){
        while (in < h){
            in++;
            t.insert(0);
        }
        t.update_least(k);
    }
    cout << t.calc_ans(t.rt) << '\n';
}
