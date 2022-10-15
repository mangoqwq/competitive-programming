#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e5 + 5;

int N, S; ll a[MN], val[MN];
struct Item{
    ll tot, pre, idx;
} st[2 * MN];
Item combine(Item a, Item b){
    if (a.pre <= a.tot + b.pre) return {a.tot + b.tot, a.pre, a.idx};
    else return {a.tot + b.tot, a.tot + b.pre, b.idx};
}
void build(int v = 1, int l = 0, int r = S - 1){
    if (l == r) st[v] = {1, 1, l};
    else{
        build(lc, l, mid), build(rc, mid + 1, r);
        st[v] = combine(st[lc], st[rc]);
    }
}
void sub(int idx, int v = 1, int l = 0, int r = S - 1){
    if (l == r) st[v].tot--, st[v].pre--;
    else{
        if (idx <= mid) sub(idx, lc, l, mid);
        else sub(idx, rc, mid + 1, r);
        st[v] = combine(st[lc], st[rc]);
    }
}
Item qry(int ql, int qr, int v = 1, int l = 0, int r = S - 1){
    if (l > qr || r < ql) return {0, inf, -1};
    if (l >= ql && r <= qr) return st[v];
    return combine(qry(ql, qr, lc, l, mid), qry(ql, qr, rc, mid + 1, r));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> S;
    if (S >= N){
        for (int i = 1; i <= N; ++i) cin >> a[i];
        sort(a + 1, a + 1 + N);
        for (int i = 1; i <= N; ++i){
            if (a[i] < i){
                cout << i - 1 << '\n';
                return 0;
            }
        }
        cout << "INF" << '\n';
        return 0;
    }
    for (int i = 1; i <= N; ++i) cin >> a[i], a[i]--;
    fill(val, val + S, 1);
    sort(a + 1, a + 1 + N);
    build();
    ll b = 0, p = 1;
    ll excess = 0;
    auto brute = [&](){
        for (int i = 0; i < S; ++i){
            excess += val[i];
            if (excess < 0){
                cout << b * S + i + 1 << '\n';
                exit(0);
            }
        }
    };
    while (p <= N){
        ll nb = a[p] / S;
        {
            auto [tot, pre, idx] = qry(0, S - 1);
            assert(pre <= tot);
            ll blks = nb - b;
            if (tot < 0) blks = min(blks, (excess + pre + 1) / -tot);
            if (pre + excess < 0){
                blks = 0;
            }
            excess += tot * blks; b += blks;
        }
        if (b != nb){
            brute(); b++; brute();
        }
        
        while (p <= N && a[p] / S == b){
            sub(a[p] % S); val[a[p] % S]--;
            p++;
        }

        auto [tot, pre, idx] = qry(0, S - 1);
        if (pre + excess < 0){
            brute(); b++; brute();
        }
        excess += tot;
        b++;
    }
    auto [tot, pre, idx] = qry(0, S - 1);
    ll blks = (excess + pre + 1) / -tot;
    if (pre + excess < 0){
        blks = 0;
    }
    excess += tot * blks; b += blks;
    brute(); b++; brute();
}
