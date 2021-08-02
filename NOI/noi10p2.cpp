#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 0;

template<typename T>
class SparseTable{
private:
    int n, layers;
    struct Data{
        T val; int idx;
        bool operator<(const Data &rhs) const{
            return tie(val, idx) < tie(rhs.val, rhs.idx);
        }
    };
    vector<vector<Data>> st;

private:
    Data op(Data a, Data b) const { return min(a, b); }

public:
    SparseTable() = default;
    SparseTable(const vector<T> &v){
        assert(!v.empty());
        n = v.size(); layers = __lg(n);
        st.assign(layers + 1, vector<Data>(n + 1));
        for (int i = 0; i <= n; ++i) st[0][i] = {v[i], i};
        for (int sz = 1; sz <= layers; ++sz)
            for (int i = 0; i + (1 << sz) - 1 <= n; ++i)
                st[sz][i] = op(st[sz - 1][i], st[sz - 1][i + (1 << (sz - 1))]);
    }
    T query_val(const int l, const int r) const{
        assert(r >= l && l >= 0 && r <= n);
        int sz = __lg(r - l + 1);
        return op(st[sz][l], st[sz][r - (1 << sz) + 1]).val;
    }
    int query_idx(const int l, const int r) const{
        assert(r >= l && l >= 0 && r <= n);
        int sz = __lg(r - l + 1);
        return op(st[sz][l], st[sz][r - (1 << sz) + 1]).idx;
    }
};

vector<int> psa;
SparseTable<int> rmq;
struct Item{
    int lo, idx, hi, i, val;
    Item(int _lo, int _hi, int _i){
        assert(_i >= _hi && _hi >= _lo);
        lo = _lo, hi = _hi, i = _i;
        idx = rmq.query_idx(_lo - 1, _hi - 1) + 1;
        val = psa[i] - psa[idx - 1];
    }
    bool operator<(const Item &x) const{ return val < x.val; }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    psa.resize(n + 1);
    for (int i = 1; i <= n; ++i){
        cin >> psa[i];
        psa[i] += psa[i - 1];
    }
    rmq = SparseTable<int>(psa);

    priority_queue<Item> pq;
    for (int i = l; i <= n; ++i){
        int lo = max(i - r + 1, 1);
        int hi = i - l + 1;
        pq.push(Item(lo, hi, i));
    }

    ll ans = 0;
    for (int chords = 1; chords <= k; ++ chords){
        assert(!pq.empty());
        auto [lo, idx, hi, i, val] = pq.top();
        pq.pop();
        ans += val;
        if (idx != lo) pq.push(Item(lo, idx-1, i));
        if (idx != hi) pq.push(Item(idx+1, hi, i));
    }
    cout << ans << '\n';
}
