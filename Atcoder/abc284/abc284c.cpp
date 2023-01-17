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
    int N, M; cin >> N >> M;
    DisjointSet dsu(N);
    for (int i = 0; i < M; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        dsu.unite(a, b);
    }
    int ans = 0;
    for (int i = 0; i < N; ++i){
        if (i == dsu.root(i)) ans++;
    }
    cout << ans << '\n';
}
