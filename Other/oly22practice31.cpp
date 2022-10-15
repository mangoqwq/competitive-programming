#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 4e5 + 10;

int N, M;
int l[2 * MN], r[2 * MN];
int nxt[MN][20];
pii st[6 * MN];
void ins(int idx, pii val, int v = 1, int l = 0, int r = 3 * M){
    if (l == r) st[v] = val;
    else{
        if (idx <= mid) ins(idx, val, lc, l, mid);
        else ins(idx, val, rc, mid + 1, r);
        st[v] = max(st[lc], st[rc]);
    }
}
pii qry(int ql, int qr, int v = 1, int l = 0, int r = 3 * M){
    if (l > qr || r < ql) return {-1, -1};
    if (l >= ql && r <= qr) return st[v];
    return max(qry(ql, qr, lc, l, mid), qry(ql, qr, rc, mid + 1, r));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    vector<int> comp;
    for (int i = 0; i < N; ++i){
        cin >> l[i] >> r[i];
        comp.push_back(l[i]);
        comp.push_back(r[i]);
    }
    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
    M = comp.size();
    for (int i = 0; i < N; ++i){
        l[i] = lower_bound(comp.begin(), comp.end(), l[i]) - comp.begin();
        r[i] = lower_bound(comp.begin(), comp.end(), r[i]) - comp.begin();
        if (r[i] < l[i]) r[i] += M;
        ins(l[i], {r[i], i});
        l[i + N] = l[i] + M;
        r[i + N] = r[i] + M;
        ins(l[i + N], {r[i + N], i + N});
    }
    for (int i = 0; i < 2 * N; ++i){
        nxt[i][0] = qry(l[i], r[i]).second;
    }
    for (int l = 1; l < 20; ++l){
        for (int i = 0; i < 2 * N; ++i){
            nxt[i][l] = nxt[nxt[i][l - 1]][l - 1];
        }
    }
    for (int i = 0; i < N; ++i){
        int ans = 1, v = i;
        for (int b = 19; b >= 0; --b){
            if (r[nxt[v][b]] < l[i] + M){
                v = nxt[v][b];
                ans += (1 << b);
            }
        }
        cout << ans + 1 << " ";
    }
    cout << '\n';

}
