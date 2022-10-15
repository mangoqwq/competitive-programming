#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const int MN = 1e5 + 1;

int N, L, R;
struct Edge{ int to, w, nxt; } adj[2 * MN];
int h[MN], T, mxdepth[MN];
double mx[MN];
struct Item{ int v; double tot; int d; };
vector<int> treemxdepth[MN];
vector<vector<Item>> trees[MN];
vector<int> ord;
int sz[MN], marked[MN];
double avg;
bool avg_can;
struct SegmentTree{
    vector<double> st; int n;
    vector<int> hist;
    void build(int _n){
        int nsz = 2 * (_n + 5);
        if (st.size() < nsz) st.resize(nsz);
        fill(st.begin(), st.begin() + nsz, -infll);
        n = _n;
    }

    void ins(int idx, double val, int v, int l, int r){
        if (l == r) return void(st[v] = max(st[v], val));
        if (idx <= mid) ins(idx, val, lc, l, mid);
        else ins(idx, val, rc, mid + 1, r);
        st[v] = max(st[lc], st[rc]);
    }
    void ins(int idx, double val){ ins(idx, val, 1, 0, n); }
    double qry(int ql, int qr, int v, int l, int r){
        if (l > qr || r < ql) return -infll;
        if (l >= ql && r <= qr) return st[v];
        else return max(qry(ql, qr, lc, l, mid), qry(ql, qr, rc, mid + 1, r));
    }
    double qry(int ql, int qr){ return qry(ql, qr, 1, 0, n); }
} st;

int get_centroid(int v){
    function<int(int, int)> getsz = [&](int v, int p){
        sz[v] = 1;
        for (int i = h[v]; i; i = adj[i].nxt){
            int to = adj[i].to, w = adj[i].w;
            if (to == p || marked[to]) continue;
            sz[v] += getsz(to, v);
        }
        return sz[v];
    };
    int n = getsz(v, v);
    function<int(int, int)> locate = [&](int v, int p){
        for (int i = h[v]; i; i = adj[i].nxt){
            int to = adj[i].to, w = adj[i].w;
            if (to == p || marked[to]) continue;
            if (sz[to] * 2 > n) return locate(to, v);
        }
        return v;
    };
    return locate(v, v);
}

void dfs(int v, int p, double tot, int d, int &mxd, vector<Item> &vec){
    mxd = max(mxd, d);
    vec.push_back({v, tot, d});
    for (int i = h[v]; i; i = adj[i].nxt){
        int to = adj[i].to, w = adj[i].w;
        if (to == p || marked[to]) continue;
        dfs(to, v, tot + w, d + 1, mxd, vec);
    }
}

void precomp(){
    T = 0;
    function<void(int)> decomp = [&](int v){
        int tmp = get_centroid(v);
        int n = sz[v];
        v = tmp;
        ord.push_back(v);
        marked[v] = 1;
        for (int i = h[v]; i; i = adj[i].nxt){
            int to = adj[i].to, w = adj[i].w;
            if (marked[to]) continue;
            trees[v].push_back(vector<Item>());
            treemxdepth[v].push_back(0);
            dfs(to, v, w, 1, treemxdepth[v].back(), trees[v].back());
            mxdepth[v] = max(mxdepth[v], treemxdepth[v].back());
        }
        for (int i = h[v]; i; i = adj[i].nxt){
            int to = adj[i].to, w = adj[i].w;
            if (marked[to]) continue;
            decomp(to);
        }
    };
    decomp(1);
}

void solve(){
    for (int v : ord){
        st.build(mxdepth[v]);
        for (int t = 0; t < trees[v].size(); ++t){
            for (int i = 0; i <= treemxdepth[v][t]; ++i){
                mx[i] = -infll;
            }
            for (auto [v, tot, d] : trees[v][t]){
                mx[d] = max(mx[d], tot - d * avg);
            }
            for (int i = 0; i <= treemxdepth[v][t]; ++i){
                if (L <= i && i <= R) avg_can |= mx[i] >= 0;
                int ql = max(0, L - i);
                int qr = min(mxdepth[v], R - i);
                if (st.qry(ql, qr) + mx[i] >= 0) avg_can = 1;
                if (avg_can) return;
            }
            for (int i = 0; i <= treemxdepth[v][t]; ++i){
                st.ins(i, mx[i]);
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> L >> R;
    for (int i = 1; i <= N - 1; ++i){
        int a, b, w; cin >> a >> b >> w;
        adj[++T] = {b, w, h[a]}, h[a] = T;
        adj[++T] = {a, w, h[b]}, h[b] = T;
    }
    precomp();
    double lo = 1, hi = 1e6;
    for (int it = 1; it <= 30; ++it){
        avg = (lo + hi) / 2;
        avg_can = 0; solve();
        if (avg_can) lo = avg;
        else hi = avg;
    }
    cout << fixed << setprecision(3) << (lo + hi) / 2 << '\n';
}
