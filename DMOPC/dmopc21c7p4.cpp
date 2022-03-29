#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

mt19937 gen;
uniform_int_distribution<int> dis(1,1e9);
int N;

struct Treap{
    struct nd{
        ll p, a, b, sz, tota, mxb, mxab;
        nd *l, *r;
        nd(ll _a, ll _b) : p(dis(gen)), a(_a), b(_b), sz(1), tota(_a), mxb(_b), mxab(_a + _b),
                    l(0), r(0) {}
    } *rt = 0;
    ll get_sz(nd *t){ return t?t->sz:0; }
    ll get_tota(nd *t){ return t?t->tota:0; }
    ll get_mxb(nd *t){ return t?t->mxb:0; }
    ll get_mxab(nd *t){ return t?t->mxab:0; }
    void pull(nd *t){
        if (!t) return;
        t->sz = 1 + get_sz(t->l) + get_sz(t->r);
        t->tota = t->a + get_tota(t->l) + get_tota(t->r);
        t->mxb = max({t->b, get_mxb(t->l), get_mxb(t->r)});
        t->mxab = max({t->a + t->b, get_mxab(t->l), get_mxab(t->r)});
    }
    void splitkey(nd *t, nd *&l, nd *&r, ll a, ll b){
        if (!t) l=r=0;
        else if (tie(t->a, t->b) <= tie(a, b)) splitkey(t->r,t->r,r,a,b), l=t;
        else splitkey(t->l,l,t->l,a,b), r=t;
        pull(t);
    }
    void splitidx(nd *t, nd *&l, nd *&r, int cnt){
        assert(cnt<=get_sz(t));
        if (!t) l=r=0;
        else if (get_sz(t->l)+1<=cnt) splitidx(t->r,t->r,r,cnt-get_sz(t->l)-1), l=t;
        else splitidx(t->l,l,t->l,cnt), r=t;
        pull(t);
    }
    void merge(nd *&t, nd *l, nd *r){
        if (!l||!r) t=l?l:r;
        else if (l->p>r->p) merge(l->r,l->r,r), t=l;
        else merge(r->l,l,r->l), t=r;
        pull(t);
    }
    void insert(ll a, ll b){
        nd *t1, *t2, *it = new nd(a, b);
        splitkey(rt, t1, t2, a, b);
        merge(rt,t1,it), merge(rt,rt,t2);
    }
    void erase(ll a, ll b){
        nd *t1, *t2, *t3;
        splitkey(rt, t1, t3, a, b);
        splitkey(t1, t1, t2, a, b - 1);
        merge(t2, t2->l, t2->r);
        merge(t1, t1, t2);
        merge(rt, t1, t3);
    }
    void print(nd *t){
        if (!t) return;
        print(t->l);
        cout << "(" << t->a << ", " << t->b << ")" << ", ";
        print(t->r);
    }
    int num_positive(){
        nd *t1, *t2;
        splitkey(rt, t1, t2, -1, inf);
        ll ret = get_sz(t2);
        merge(rt, t1, t2);
        return ret;
    }
    nd* getmax(nd *t){
        assert(t);
        if (t->r) return getmax(t->r);
        return t;
    }
    ll mx_kdist(int k){
        nd *t1, *t2;
        splitidx(rt, t1, t2, N - k);
        ll v1 = get_tota(t2) + get_mxab(t1);
        ll v2 = get_tota(t2) + get_mxb(t2) + getmax(t1)->a;
        merge(rt, t1, t2);
        return max(v1, v2);
    }
};

ll a[MN], b[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    Treap t;
    cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> a[i] >> b[i]; a[i] -= b[i];
        t.insert(a[i], b[i]);
    }
    int Q; cin >> Q;
    while (Q--){
        int op; cin >> op;
        if (op == 0){
            ll r; cin >> r;
            int lo = 0, hi = min(t.num_positive(), N - 1);
            if (t.mx_kdist(hi) < r){
                cout << -1 << '\n';
                continue;
            }
            while (lo < hi){
                int mid = (lo + hi) >> 1;
                if (t.mx_kdist(mid) >= r) hi = mid;
                else lo = mid + 1;
            }
            if (t.mx_kdist(lo) >= r) cout << lo + 1 << '\n';
            else cout << -1 << '\n';
        }
        else{
            t.erase(a[op], b[op]);
            cin >> a[op] >> b[op]; a[op] -= b[op];
            t.insert(a[op], b[op]);
        }
    }
}
