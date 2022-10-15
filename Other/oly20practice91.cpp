#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

mt19937 gen(0);
uniform_int_distribution<int> dis(1, 1e9);
struct Treap{
    struct nd{
        // tot = sum of v
        // cnt = sum of active v
        // sz = number of nodes
        // num = number of active nodes
        ll v, p, tot, cnt, sz, num; int lz, active; // 1 disable, 2 enable
        nd *lc, *rc;
        nd(ll _v) : v(_v), p(dis(gen)), tot(v), cnt(v), sz(1), num(1), lz(0), active(1), lc(0), rc(0) {}
    } *rt = 0;
    ll get_tot(nd *t){ return t ? t->tot : 0; }
    ll get_cnt(nd *t){ return t ? t->cnt : 0; }
    ll get_v(nd *t){ return (t && t->active) ? t->v : 0; }
    ll get_sz(nd *t){ return t ? t->sz : 0; }
    ll get_num(nd *t){ return t ? t->num : 0; }
    void pull(nd *t){
        assert(t);
        push(t->lc); push(t->rc);
        t->tot = get_tot(t->lc) + get_tot(t->rc) + t->v;
        t->cnt = get_cnt(t->lc) + get_cnt(t->rc) + (t->active ? t->v : 0 );
        t->sz = get_sz(t->lc) + get_sz(t->rc) + 1;
        t->num = get_num(t->lc) + get_num(t->rc) + (t->active ? 1 : 0);
    }
    void push(nd *t){
        if (!t || t->lz == 0) return;
        if (t->lz == 1) t->cnt = t->active = t->num = 0;
        if (t->lz == 2) t->cnt = t->tot, t->active = 1, t->num = t->sz;
        if (t->lc) t->lc->lz = t->lz;
        if (t->rc) t->rc->lz = t->lz;
        t->lz = 0;
    }
    void split(nd *t, ll v, nd *&l, nd *&r){
        push(t);
        if (!t) return void(l = r = 0);
        if (t->v < v) split(t->rc, v, t->rc, r), l = t;
        else split(t->lc, v, l, t->lc), r = t;
        pull(t);
    }
    void merge(nd *&t, nd *l, nd *r){
        push(l); push(r);
        if (!l || !r) return void(t = l ? l : r);
        if (l->p > r->p) merge(l->rc, l->rc, r), t = l;
        else merge(r->lc, l, r->lc), t = r;
        pull(t);
    }
    void ins(ll v){
        nd *t1, *t2;
        split(rt, v, t1, t2);
        merge(rt, t1, new nd(v));
        merge(rt, rt, t2);
    }
    void rem(ll v){
        nd *t1, *t2, *t3;
        split(rt, v, t1, t2);
        split(t2, v + 1, t2, t3);
        merge(t1, t1, t2->lc);
        merge(t3, t2->rc, t3);
        merge(rt, t1, t3);
    }
    void print(nd *t){
        if (!t) return;
        print(t->lc);
        cout << t->v << " ";
        print(t->rc);
    }
    ll get_min(nd *t){
        if (!t) return 1e18;
        if (t->lc) return get_min(t->lc);
        else return t->v;
    }
    ll find_max(nd *t){
        push(t);
        ll ret;
        if (get_num(t->rc)) ret = find_max(t->rc);
        else if (t->active) t->active = 0, ret = t->v;
        else ret = find_max(t->lc);
        pull(t);
        return ret;
    }
    ll go(nd *t, ll &s, const ll tar){
        if (!get_cnt(t)) return 0;
        push(t); push(t->rc);
        ll fish = get_cnt(t->rc), ret = 0;
        if (s + fish >= tar) ret += go(t->rc, s, tar);
        else{
            s += get_v(t) + fish;
            ret += t->active + get_num(t->rc);

            if (t->rc) t->rc->lz = 1;
            t->active = 0;

            ret += go(t->lc, s, tar);
        }
        pull(t);
        return ret;
    }
    ll eat(ll &s, ll k){
        nd *t1, *t2;
        split(rt, s, t1, t2);
        ll tar = min(k, get_min(t2) + 1), ret = 0;
        ret = go(t1, s, tar);
        merge(rt, t1, t2);
        return ret;
    }
    ll query(ll s, ll k){
        ll ans = 0;
        while (s < k){
            ll bite = eat(s, k);
            if (bite == 0) return reset(rt), -1;
            ans += bite;
        }
        reset(rt);
        return ans;
    }
    void reset(nd *t){ if (t) t->lz = 2, push(t); }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
#endif
    int N; cin >> N;
    Treap tr;
    for (int i = 1; i <= N; ++i){
        ll w; cin >> w;
        tr.ins(w);
    }
    int Q; cin >> Q;
    for (int i = 1; i <= Q; ++i){
        int op; cin >> op;
        if (op == 1){
            ll s, k; cin >> s >> k;
            cout << tr.query(s, k) << '\n';
            cout.flush();
        }
        if (op == 2){
            ll w; cin >> w;
            tr.ins(w);
        }
        if (op == 3){
            ll w; cin >> w;
            tr.rem(w);
        }
    }
}
