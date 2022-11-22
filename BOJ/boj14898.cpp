#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MN = 1e6+1;
#define mid ((l+r) >> 1)
#define lc (t+1)
#define rc (t + 2 * (mid - l + 1))

vector<int> st[2*MN + 1];
vector<int> v;
void build(int t, int l, int r){
    if (l == r){
        st[t] = {v[l]};
        return;
    }
    build(lc, l, mid), build(rc, mid+1, r);
    st[t].resize(st[lc].size() + st[rc].size());
    merge(st[lc].begin(), st[lc].end(), st[rc].begin(), st[rc].end(), st[t].begin());
}

int qry(int ql, int qr, int t, int l, int r){
    if (l > qr || r < ql) return 0;
    if (l >= ql && r <= qr){
        return lower_bound(st[t].begin(), st[t].end(), ql) - st[t].begin();
    }
    return qry(ql, qr, lc, l, mid) + qry(ql, qr, rc, mid+1, r);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> a(N);
    v.resize(N);
    map<int, int> seen;
    for (int i = 0; i < N; ++i){
        cin >> a[i];
        if (!seen.count(a[i])) seen[a[i]] = -1;
        v[i] = seen[a[i]];
        seen[a[i]] = i;
    }
    build(1, 0, N-1);
    int ans = 0;
    int Q; cin >> Q;
    while (Q--){
        int l, r; cin >> l >> r;
        l += ans;
        l--, r--;
        cout << (ans = qry(l, r, 1, 0, N-1)) << '\n';
    }
}
