#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;

template <typename T>
class SegmentTree{
#define __mid ((l + r) >> 1)
#define __lc (v + 1)
#define __rc (v + 2 * (__mid - l + 1))
private:
    int N;
    vector<T> st;
    T construct(int v, int l, int r, const vector<T> &vec){
        if (l == r) return st[v] = vec[l];
        return st[v] = op(construct(__lc, l, __mid, vec), construct(__rc, __mid + 1, r, vec));
    }
    void update(int idx, T val, int v, int l, int r){
        if (l == r){ update_op(st[v], val); return; }
        if (idx <= __mid) update(idx, val, __lc, l, __mid);
        else update(idx, val, __rc, __mid + 1, r);
        st[v] = op(st[__lc], st[__rc]);
    }
    T query(int ql, int qr, int v, int l, int r){
        if (l > qr || r < ql) return identity_element();
        if (l >= ql && r <= qr) return st[v];
        return op(query(ql, qr, __lc, l, __mid), query(ql, qr, __rc, __mid + 1, r));
    }
#undef __mid
#undef __lc
#undef __rc
private:
    void update_op(T &v, T val){ v = val; }
    T op(T a, T b){ return min(a, b); }
    T identity_element(){ return inf; }

public:
    SegmentTree() = default;
    SegmentTree(const vector<T> &vec){
        N = vec.size() - 1;
        st.resize(2 * N + 1, identity_element());
        construct(1, 1, N, vec);
    }
    void update(int idx, T val){
        assert(1 <= idx && idx <= N);
        update(idx, val, 1, 1, N);
    }
    T query(int ql, int qr){
        assert(qr >= ql);
        assert(1 <= ql && qr <= N);
        return query(ql, qr, 1, 1, N);
    }
};
SegmentTree<int> st(vector<int>(MN, inf));
int a[MN], sz[MN], pos[MN];
priority_queue<int, vector<int>, greater<int>> s[MN];
void fix(int _sz){
    while (!s[_sz].empty() && sz[s[_sz].top()] != _sz){
        s[_sz].pop();
    }
    if (s[_sz].empty()) st.update(_sz, inf);
    else st.update(_sz, s[_sz].top());
}
void ins(int sz, int v){
    s[sz].push(v);
    fix(sz);
    st.update(sz, s[sz].top());
}
int qry(int sz){
    if (sz < 1) return inf;
    fix(sz);
    return st.query(1, sz);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    for (int i = 1; i <= N; ++i) sz[i] = 1;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        pos[a[i]] = i;
        ins(sz[a[i]], a[i]);
    }
    for (int i = 1; i < N; ++i){
        int mn = qry(K - sz[a[i]]);

        if (mn >= a[i]){
            int tmp = sz[a[i]];
            sz[a[i]] = inf;
            fix(tmp);
            continue;
        }
        int j = pos[mn];


        int tmp1 = sz[a[i]], tmp2 = sz[a[j]];
        int cur = sz[a[i]] + sz[a[j]];
        sz[a[j]] = inf;
        sz[a[i]] = cur;
        fix(tmp1);
        fix(tmp2);
        ins(sz[a[i]], a[i]);

        swap(a[i], a[j]); swap(pos[a[i]], pos[a[j]]);
    }
    
    for (int i = 1; i <= N; ++i){
        cout << a[i] << (i == N ? '\n' : ' ');
    }
}
