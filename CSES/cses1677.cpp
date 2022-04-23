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
    int N, M, K; cin >> N >> M >> K;
    set<pair<int, int>> edges;
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        if (b < a) swap(a, b);
        edges.insert({a, b});
    }
    vector<pair<int, int>> qs(K);
    vector<int> ans(K);
    for (int i = 0; i < K; ++i){
        int a, b; cin >> a >> b;
        if (b < a) swap(a, b);
        edges.erase({a, b});
        qs[i] = {a, b};
    }
    DisjointSet dsu(N + 1);
    int ccs = N;
    for (auto [a, b] : edges) ccs -= dsu.unite(a, b);
    for (int i = K - 1; i >= 0; --i){
        ans[i] = ccs;
        ccs -= dsu.unite(qs[i].first, qs[i].second);
    }
    for (int i = 0; i < K; ++i) cout << ans[i] << " ";
    cout << '\n';
}
