#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int N, Q, a[MN];
vector<int> vec[MN];
vector<int> st[2 * MN];

void build(int v = 1, int l = 1, int r = N){
    if (l == r) return void(st[v] = vec[l]);
    build(lc, l, mid); build(rc, mid + 1, r); st[v].resize(st[lc].size() + st[rc].size());
    merge(st[lc].begin(), st[lc].end(), st[rc].begin(), st[rc].end(), st[v].begin());
}

int cnt(int ql, int qr, int v){
    return upper_bound(st[v].begin(), st[v].end(), qr) - 1
         - lower_bound(st[v].begin(), st[v].end(), ql) + 1;
}
int walk(int ql, int qr, int k, int v = 1, int l = 1, int r = N){
    if (l == r) return l;
    int cntl = cnt(ql, qr, lc);
    if (k <= cntl) return walk(ql, qr, k, lc, l, mid);
    else return walk(ql, qr, k - cntl, rc, mid + 1, r);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    map<int, int> mp, comp;
    int T = 0;
    for (int i = 1; i <= N; ++i) comp[a[i]] = 0;
    for (auto &[a, b] : comp) b = ++T, mp[b] = a;
    for (int i = 1; i <= N; ++i) vec[comp[a[i]]].push_back(i);
    build();
    int ans = 0;
    while (Q--){
        int l, r, k; cin >> l >> r >> k;
        l ^= ans, r ^= ans, k ^= ans;
        cout << (ans = mp[walk(l, r, k)]) << '\n';
    }
}
