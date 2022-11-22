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

struct Edge{
    char c; int a, b;
    bool operator<(const Edge &other) const{
        return c > other.c;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    while (true){
        int N, M, K; cin >> N >> M >> K;
        if (N == 0 && M == 0 && K == 0) break;
        vector<Edge> edges(M);
        for (int i = 0; i < M; ++i){
            cin >> edges[i].c >> edges[i].a >> edges[i].b;
            edges[i].a--;
            edges[i].b--;
        }
        sort(edges.begin(), edges.end());
        DisjointSet needs(N), dsu(N);
        int cnt = 0;
        for (auto [c, a, b] : edges){
            if (needs.root(a) != needs.root(b)){
                needs.unite(a, b);
                if (c == 'B'){
                    dsu.unite(a, b);
                    cnt++;
                }
            }
        }
        reverse(edges.begin(), edges.end());
        for (auto [c, a, b] : edges){
            if (c == 'B' && cnt >= K) continue;
            if (dsu.root(a) != dsu.root(b)){
                dsu.unite(a, b);
                if (c == 'B') cnt++;
            }
        }
        cout << (cnt == K && dsu.sz[dsu.root(0)] == N) << '\n';
    }
}
