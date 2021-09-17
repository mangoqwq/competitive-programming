#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

mt19937 gen;
uniform_int_distribution<int> dis(1, 1e9);
ll sum(ll x){ return x * (x + 1) / 2; }
ll sum(ll l, ll r){ return sum(r) - sum(l - 1); }
struct Treap{
    struct nd{
        // !! set applies before lz !!
        ll v, p, sz;
        ll tot, lz, x, set;
        // x is delta, lz is start
        nd *l, *r;
        nd(ll _v) : v(_v), p(dis(gen)), sz(1), tot(_v), lz(0), x(0), l(0), r(0), set(-inf) {};
    } *rt = 0;
    ll get_sz(nd *t){ return t ? t->sz : 0; };
    ll get_tot(nd *t){ return t ? t->tot : 0; };
    void push(nd *t){
        if (!t) return;
        if (t->set != -inf){
            t->v = t->set;
            t->tot = t->set * t->sz;
            if (t->l) t->l->set = t->set, t->l->lz = t->l->x = 0;
            if (t->r) t->r->set = t->set, t->r->lz = t->r->x = 0;
            t->set = -inf;
        }
        if (t->x){
            t->v += (get_sz(t->l) + 1) * t->x + t->lz;
            t->tot += sum(t->sz) * (t->x) + t->sz * t->lz;
            if (t->l){
                t->l->lz += t->lz;
                t->l->x += t->x;
            }
            if (t->r){
                t->r->lz += t->lz + (get_sz(t->l) + 1) * t->x;
                t->r->x += t->x;
            }
            t->lz = t->x = 0;
        }
    }
    void pull(nd *t){
        if (!t) return;
        push(t->l), push(t->r);
        t->sz = 1 + get_sz(t->l) + get_sz(t->r);
        t->tot = t->v + get_tot(t->l) + get_tot(t->r);
    }
    // l is <= idx, r is > idx
    void split(nd *t, nd *&l, nd *&r, int idx){
        // cout << idx << " " << get_sz(t) << '\n';
        assert(idx <= get_sz(t));
        push(t);
        if (!t) l = r = 0;
        else if (get_sz(t->l) + 1 <= idx) split(t->r, t->r, r, idx - get_sz(t->l) - 1), l = t;
        else split(t->l, l, t->l, idx), r = t;
        pull(t);
    }
    void merge(nd *&t, nd *l, nd *r){
        push(l); push(r);
        if (!l || !r) t = l ? l : r;
        else if (l->p > r->p) merge(l->r, l->r, r), t = l;
        else merge(r->l, l, r->l), t = r;
        pull(t);
    }
    void set(ll l, ll r, ll x){
        nd *t1, *t2, *t3;
        split(rt, t1, t2, l - 1);
        split(t2, t2, t3, r - l + 1);
        t2->set = x;
        merge(rt, t1, t2);
        merge(rt, rt, t3);
    }
    void affine(ll l, ll r, ll x){
        nd *t1, *t2, *t3;
        split(rt, t1, t2, l - 1);
        split(t2, t2, t3, r - l + 1);
        t2->x += x;
        merge(rt, t1, t2);
        merge(rt, rt, t3);
    }
    void insert(ll idx, ll val){
        nd *t1, *t2;
        split(rt, t1, t2, idx - 1);
        merge(rt, t1, new nd(val));
        merge(rt, rt, t2);
    }
    ll query_sum(ll l, ll r){
        nd *t1, *t2, *t3;
        split(rt, t1, t2, l - 1);
        split(t2, t2, t3, r - l + 1);
        ll ans = get_tot(t2);
        merge(rt, t1, t2);
        merge(rt, rt, t3);
        return ans;
    }
    void print(nd *t){
        if (!t) return;
        push(t);
        print(t->l);
        cout << t->v << " ";
        print(t->r);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    Treap t;
    for (int i = 1; i <= n; ++i){
        int x; cin >> x;
        t.insert(i, x);
    }
    while (q--){
        int op; cin >> op;
        if (op == 1){
            int a, b, x; cin >> a >> b >> x;
            t.set(a, b, x);
        }
        if (op == 2){
            int a, b, x; cin >> a >> b >> x;
            t.affine(a, b, x);
        }
        if (op == 3){
            int c, x; cin >> c >> x;
            t.insert(c, x);
        }
        if (op == 4){
            int a, b; cin >> a >> b;
            cout << t.query_sum(a, b) << '\n';
        }
        // t.print(t.rt);
    }
}
