#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e4 + 1, MM = 1e5 + 1, MQ = 1e5 + 1;
const int SZ = 1000;

struct DisjointSet{
    vector<int> p, sz;
    vector<pair<int,int>> hist;
    DisjointSet(int N){
        p = vector<int>(N + 1);
        sz = vector<int>(N + 1);
        reset();
    }
    int Find(int x){ return p[x] == x ? x : Find(p[x]); }
    void Union(int a, int b){
        a = Find(a), b = Find(b);
        if (a == b) a = -1, b = -1;
        else{
            if (sz[b] > sz[a]) swap(a, b);
            p[b] = a, sz[a] += sz[b];
        }
        hist.push_back({a, b});
    }
    void undo(){
        assert(!hist.empty());
        auto [a, b] = hist.back(); hist.pop_back();
        if (a == -1) return;
        sz[a] -= sz[b], p[b] = b;
    }
    int getsz(int v){ return sz[Find(v)]; }
    void reset(){
        hist.clear();
        iota(p.begin(), p.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }
};
struct Edge{ int a, b, w; } all_edges[MM];
struct Query{ int v, w, t; };
int changes[MM], ans[MQ];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; ++i){
        int a, b, w; cin >> a >> b >> w;
        all_edges[i] = {a, b, w};
    }
    int Q; cin >> Q;
    vector<Query> qs1, qs2;
    DisjointSet dsu(N);
    for (int _ = 1; _ <= Q; ++_){
        int op, v, w; cin >> op >> v >> w;
        if (op == 1) qs1.push_back({v, w, _}), all_edges[v].w = -abs(all_edges[v].w);
        if (op == 2) qs2.push_back({v, w, _});
        if ((Q - _) % SZ) continue;

        vector<Edge> edges;
        vector<int> look;
        dsu.reset();
        for (int i = 1; i <= M; ++i){
            if (all_edges[i].w > 0) edges.push_back(all_edges[i]);
            else look.push_back(i);
        }
        sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.w > b.w; });
        sort(qs2.begin(), qs2.end(), [](Query a, Query b){ return a.w > b.w; });
        int pl = 0;
        for (auto [v, w, t] : qs2){
            while (pl != edges.size() && edges[pl].w >= w) dsu.Union(edges[pl].a, edges[pl].b), ++pl;

            for (int i : look) changes[i] = -all_edges[i].w;
            for (auto [ev, ew, et] : qs1){
                if (et <= t) changes[ev] = ew;
                else break;
            }
            int T = 0;
            for (int i : look){
                int ew = changes[i];
                if (ew >= w){
                    dsu.Union(all_edges[i].a, all_edges[i].b);
                    ++T;
                }
            }
            ans[t] = dsu.getsz(v);

            for (int i = 1; i <= T; ++i) dsu.undo();
        }

        for (auto [v, w, t] : qs1) all_edges[v].w = w;
        for (int i = 1; i <= M; ++i) all_edges[i].w = abs(all_edges[i].w);
        qs1.clear(), qs2.clear(); look.clear();
    }
    for (int i = 1; i <= Q; ++i){
        if (ans[i]) cout << ans[i] << '\n';
    }
}
