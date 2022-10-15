#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int bit[MN], ans[MN], arr[MN];
void ins(int i, int val){ for (; i < MN; i += i & -i) bit[i] += val; }
int qry(int i){ int ret = 0; for (; i; i -=i & -i) ret += bit[i]; return ret; }
int qry(int l, int r){ return qry(r) - qry(l - 1); }
struct Query{ int op, x, y, k, id; };
void cdq(vector<Query> &qs, int L, int R){
    if (qs.empty()) return;
    int mid = (L + R) >> 1;
    if (L == R){
        for (auto &cur: qs){
            auto &[op, x, y, k, id] = cur;
            if (op == 2) ans[id] = mid;
        }
        return;
    }
    vector<Query> ql, qr;
    for (auto &cur : qs){
        auto &[op, x, y, k, id] = cur;
        if (op == 1){
            if (y <= mid) ins(x, k);
            if (y <= mid) ql.push_back(cur);
            if (y > mid) qr.push_back(cur);
        }
        if (op == 2){
            int cnt = qry(x, y);
            if (k <= cnt) ql.push_back(cur);
            if (k > cnt) k -= cnt, qr.push_back(cur);
        }
    }
    cdq(ql, L, mid), cdq(qr, mid + 1, R);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<Query> qs;
    for (int i = 1; i <= N; ++i){
        int y; cin >> y;
        qs.push_back({1, i, y, 1});
        arr[i] = y;
    }
    int M; cin >> M;
    for (int i = 1; i <= M; ++i){
        int op; cin >> op;
        if (op == 1){
            int x, y; cin >> x >> y;
            qs.push_back({1, x, arr[x], -1});
            qs.push_back({1, x, y, 1});
            arr[x] = y;
        }
        if (op == 2){
            int x, y, k; cin >> x >> y >> k;
            qs.push_back({2, x, y, k, i});
        }
    }
    for (int i = 1; i <= N; ++i){
        if (arr[i]){
            qs.push_back({1, i, arr[i], -1});
            arr[i] = 0;
        }
    }
    cdq(qs, 1, 1e9);
    for (auto &[op, x, y, k, id] : qs){
        if (op == 2) cout << ans[id] << '\n';
    }
}
