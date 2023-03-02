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
    int N, K, R; cin >> N >> K >> R;
    vector<vector<int>> adj(N);
    for (int i = 0; i < N-1; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    const int L = 20;
    vector<vector<int>> up(N, vector<int>(L));
    vector<int> dist(N);
    vector<int> in(N), out(N);
    int T = 0;
    auto dfs = [&](auto self, int v, int p) -> void {
        in[v] = ++T;
        up[v][0] = p;
        for (int i = 1; i < L; ++i){
            up[v][i] = up[up[v][i-1]][i-1];
        }
        for (int to : adj[v]){
            if (to == p) continue;
            dist[to] = dist[v] + 1;
            self(self, to, v);
        }
        out[v] = T;
    };
    dfs(dfs, 0, 0);

    auto is_anc = [&](int a, int b) -> bool {
        return in[a] <= in[b] && out[a] >= out[b];
    };
    auto lca = [&](int a, int b) -> int {
        if (is_anc(a, b)) return a;
        if (is_anc(b, a)) return b;
        for (int l = L-1; l >= 0; --l){
            if (!is_anc(up[b][l], a)){
                b = up[b][l];
            }
        }
        return up[b][0];
    };
    auto pair_dist = [&](int a, int b) -> int {
        return dist[a] + dist[b] - 2 * dist[lca(a, b)];
    };
    auto step_up = [&](int v, int d) -> int {
        for (int l = L-1; l >= 0; --l){
            if ((1 << l) <= d) v = up[v][l], d -= (1<<l);
        }
        return v;
    };
    auto step_towards = [&](int a, int b, int d) -> int {
        int l = lca(a, b);
        int diff = min((K+1)/2, pair_dist(a, l));
        a = step_up(a, diff);
        int left = (K+1)/2 - diff;
        if (left) a = step_up(b, pair_dist(b, l) - left);
        return a;
    };

    vector<int> col(N, -1);
    queue<int> q;
    vector<int> restd(N, 1e9);
    int rt;
    for (int i = 0; i < R; ++i){
        int x; cin >> x;
        x--;
        col[x] = x;
        restd[x] = 0;
        q.push(x);
        rt = x;
    }
    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int to : adj[v]){
            int nd = restd[v] + 1;
            if (nd < restd[to]){
                restd[to] = nd;
                if (2*nd <= K) col[to] = col[v];
                q.push(to);
            }
        }
    }

    DisjointSet dsu(N);
    auto build = [&](auto self, int v, int p, int lst) -> void {
        if (col[v] != -1 && col[v] != lst){
            if (pair_dist(col[v], lst) <= K) dsu.unite(col[v], lst);
            lst = col[v];
        }
        for (int to : adj[v]){
            if (to == p) continue;
            self(self, to, v, lst);
        }
    };

    build(build, rt, rt, rt);
    int Q; cin >> Q;
    while (Q--){
        int a, b; cin >> a >> b;
        a--, b--;
        bool ans = [&]() -> bool {
            if (pair_dist(a, b) <= K) return 1;
            auto go = [&](int a, int b) -> bool {
                a = step_towards(a, b, (K+1)/2);
                b = step_towards(b, a, (K+1)/2);
                return col[a] != -1 && col[b] != -1 && dsu.root(col[a]) == dsu.root(col[b]);
            };
            return go(a, b) || go(b, a);
        }();
        cout << (ans ? "YES" : "NO") << '\n';
    }
}
