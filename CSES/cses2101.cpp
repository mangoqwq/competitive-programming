#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct DisjointSet{
    vector<int> p, sz;
    DisjointSet(int N){
        p.resize(N);
        iota(p.begin(), p.end(), 0);
        sz.resize(N, 1);
    }
    int root(int x){
        return p[x] == x ? x : p[x] = root(p[x]);
    }
    bool unite(int a, int b){
        a = root(a), b = root(b);
        if (a == b) return 0;
        if (sz[b] > sz[a]) swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return 1;
    }
};


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, Q; cin >> N >> M >> Q;
    DisjointSet dsu(N + 1);
    struct Edge{ int to, w; };
    vector<vector<Edge>> adj(N + 1);
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        if (dsu.unite(a, b)){
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
        }
    }
    int L = __lg(N), T = 0;
    vector<int> in(N + 1), out(N + 1), rt(N + 1);
    vector<vector<int>> up(N + 1, vector<int>(L + 1));
    vector<vector<int>> st(N + 1, vector<int>(L + 1));
    function<void(int, int)> dfs = [&](int v, int p){
        in[v] = ++T;
        up[v][0] = p;
        for (int i = 1; i <= L; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
        for (int i = 1; i <= L; ++i) st[v][i] = max(st[v][i - 1], st[up[v][i - 1]][i - 1]);
        for (auto [to, w] : adj[v]){
            if (to == p) continue;
            st[to][0] = w;
            rt[to] = rt[v];
            dfs(to, v);
        }
        out[v] = T;
    };
    for (int i = 1; i <= N; ++i){
        if (!in[i]) st[i][0] = 1e9, rt[i] = i, dfs(i, i);
    }
    function<bool(int, int)> is = [&](int a, int b) -> bool{
        return in[a] <= in[b] && out[a] >= out[b];
    };
    while (Q--){
        int a, b; cin >> a >> b;
        if (rt[a] != rt[b]){
            cout << -1 << '\n';
            continue;
        }
        if (a == b){
            cout << 0 << '\n';
            continue;
        }
        int ans = 0;
        for (int i = L; i >= 0; --i){
            if (!is(up[a][i], b)){
                ans = max(ans, st[a][i]);
                a = up[a][i];
            }
            if (!is(up[b][i], a)){
                ans = max(ans, st[b][i]);
                b = up[b][i];
            }
        }
        int l;
        if (up[a][0] == b) l = b;
        else l = up[b][0];
        if (a != l) ans = max(ans, st[a][0]);
        if (b != l) ans = max(ans, st[b][0]);
        cout << ans << '\n';
    }
}
