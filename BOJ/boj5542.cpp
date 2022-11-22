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
    int N, M, K, Q; cin >> N >> M >> K >> Q;
    struct Edge{ int to, w; };
    vector<vector<Edge>> adj(N);
    for (int i = 0; i < M; ++i){
        int a, b, w; cin >> a >> b >> w;
        a--, b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    vector<int> dist(N, 1e9);
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 0; i < K; ++i){
        int f; cin >> f; f--;
        dist[f] = 0;
        pq.push({dist[f], f});
    }
    while (!pq.empty()){
        auto [d, v] = pq.top(); pq.pop();
        if (d != dist[v]) continue;
        for (auto [to, w] : adj[v]){
            if (w + d < dist[to]){
                dist[to] = w + d;
                pq.push({dist[to], to});
            }
        }
    }

    vector<int> ord(N);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return dist[i] > dist[j];
    });
    struct Query{ int a, b, id; };
    vector<Query> qs(Q);
    for (int i = 0; i < Q; ++i){
        cin >> qs[i].a >> qs[i].b;
        qs[i].a--, qs[i].b--;
        qs[i].id = i;
    }
    vector<int> ans(Q);

    vector<int> ls = {0}, rs = {N};
    vector<vector<Query>> bi = {qs};
    int done = 0;
    while (done < Q){
        DisjointSet dsu(N);
        vector<int> in(N);
        vector<int> nls, nrs;
        vector<vector<Query>> nbi;
        int p = 0;
        for (int i = 0; i < ls.size(); ++i){
            int m = (ls[i] + rs[i]) >> 1;
            while (p < m){
                int v = ord[p];
                in[v] = 1;
                for (auto [to, w] : adj[v]){
                    if (in[to]) dsu.unite(v, to);
                }
                p++;
            }
            vector<Query> lef, rig;
            for (auto [a, b, id] : bi[i]){
                if (ls[i] + 1 == rs[i]){
                    ans[id] = dist[ord[p]];
                    done++;
                }
                if (dsu.root(a) == dsu.root(b)){
                    lef.push_back({a, b, id});
                }
                else{
                    rig.push_back({a, b, id});
                }
            }
            nls.push_back(ls[i]);
            nrs.push_back(m);
            nbi.push_back(lef);

            nls.push_back(m);
            nrs.push_back(rs[i]);
            nbi.push_back(rig);
        }
        swap(nls, ls);
        swap(nrs, rs);
        swap(nbi, bi);
    }
    for (int i = 0; i < Q; ++i){
        cout << ans[i] << '\n';
    }
}
