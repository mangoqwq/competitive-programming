#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int N, Q;
map<ll, int> st[MN];
void ins(int i, ll val1, ll val2, int v = 1, int l = 1, int r = N){
    if (l == r){
        st[v].clear();
        st[v][val1] = 1;
        st[v][val2] = 1;
        return;
    }
    if (i <= mid) ins(i, val1, val2, lc, l, mid);
    else ins(i, val1, val2, rc, mid + 1, r);
    st[v].clear();
    for (auto [x, cnt] : st[lc]) st[v][x] = cnt + (st[rc].count(x) ? st[rc][x] : 0);
}

map<ll, int> qry(int ql, int qr, int v = 1, int l = 1, int r = N){
    if (ql > r || qr < l) return map<ll, int>();
    if (l >= ql && r <= qr) return st[v];
    map<ll, int> ml = qry(ql, qr, lc, l, mid);
    map<ll, int> mr = qry(ql, qr, rc, mid + 1, r);
    map<ll, int> ret;
    if (mr.size() > ml.size()) swap(ml, mr);
    for (auto [x, cnt] : ml) ret[x] = ml[x] + mr[x];
    return ret;
}

ll s[MN], v[MN], a[MN];
pair<ll, ll> sect(int i, int j){
    if (a[i] == a[j]){
        if (v[i] == v[j]){
            return {(s[j] == s[i] ? 1 : -1), (s[j] == s[i] ? 1 : -1)};
        }
        if ((s[j] - s[i]) % (v[i] - v[j])) return {-1, -1};
        return {(s[j] - s[i]) / (v[i] - v[j]), (s[j] - s[i]) / (v[i] - v[j])};
    }
    ll qa = a[i] - a[j], qb = v[i] - v[j], qc = s[i] - s[j];
    ll dis = qb * qb - 4 * qa * qc;
    if (dis < 0) return {-1, -1};
    ll lo = 0, hi = 1e9, rt;
    while (lo < hi){
        rt = (lo + hi + 1) >> 1;
        if (rt * rt > dis) hi = rt - 1;
        else lo = rt;
    }
    rt = lo;
    if (rt * rt != dis){
        return {-1, -1};
    }
    ll v1, v2;
    if ((-qb + rt) % (2 * qa)) v1 = -1;
    else v1 = (-qb + rt) / (2 * qa);
    if ((-qb - rt) % (2 * qa)) v2 = -1;
    else v2 = (-qb - rt) / (2 * qa);
    if (rt == 0) return {v1, -1};
    if (v1 < 0) v1 = -1;
    if (v2 < 0) v2 = -1;
    return {v1, v2};
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        cin >> s[i] >> v[i] >> a[i];
        v[i] = v[i] * 2 - a[i];
        s[i] *= 2;
    }
    for (int i = 1; i < N; ++i){
        auto [p1, p2] = sect(i, i + 1);
        ins(i, p1, p2);
    }
    while (Q--){
        int op; cin >> op;
        if (op == 1){
            int i; cin >> i;
            cin >> s[i] >> v[i] >> a[i];
            v[i] = v[i] * 2 - a[i];
            s[i] *= 2;
            if (i != 1){
                auto [p1, p2] = sect(i - 1, i);
                ins(i - 1, p1, p2);
            }
            if (i != N){
                auto [p1, p2] = sect(i, i + 1);
                ins(i, p1, p2);
            }
        }
        else{
            int l, r; cin >> l >> r;
            assert(l < r);
            map<ll, int> mp = qry(l, r - 1);
            ll x = (--mp.end())->first;
            int cnt = (--mp.end())->second;
            mp.erase(--mp.end());
            if (!mp.empty() && (--mp.end())->second > cnt){
                x = (--mp.end())->first;
                cnt = (--mp.end())->second;
            }
            if (x < 0 || cnt != r - l) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
    }
}

/*
2 1
0 1 0
1 0 0
2 1 2

3 1
-1 2 1
8 -3 2
44 1 0
2 1 3
*/
