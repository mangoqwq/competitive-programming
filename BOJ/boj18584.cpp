#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    const int B = 100;
    const int MW = 20000;
    int N, Q; cin >> N >> Q;

    struct Edge{ int to, w; };
    vector<vector<Edge>> adj(N+1);
    for (int i = 1; i <= N-1; ++i){
        int a, b, w; cin >> a >> b >> w;
        w--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<int> in(N+1), out(N+1), dep(N+1);
    const int L = 17;
    vector<vector<int>> up(N+1, vector<int>(L+1));
    vector<vector<int>> smol(N+1, vector<int>(B+1));
    int T = 0;
    auto dfs = [&](auto self, int v, int p) -> void{
        in[v] = ++T;
        up[v][0] = p;
        for (int i = 1; i <= L; ++i){
            up[v][i] = up[up[v][i-1]][i-1];
        }
        for (auto [to, w] : adj[v]){
            if (to == p) continue;
            dep[to] = dep[v] + 1;
            for (int i = 1; i <= B; ++i){
                smol[to][i] = smol[v][i] + w/i;
            }
            self(self, to, v);
        }
        out[v] = T;
    };
    dfs(dfs, 1, 1);

    auto is_anc = [&](int a, int b){ return in[a] <= in[b] && out[a] >= out[b]; };
    auto lca = [&](int a, int b) -> int{
        if (is_anc(a, b)) return a;
        if (is_anc(b, a)) return b;
        for (int i = L; i >= 0; --i){
            if (!is_anc(up[a][i], b)) a = up[a][i];
        }
        return up[a][0];
    };

    vector<ll> ans(Q+1);
    struct Item{ int id, f, c; };
    vector<vector<Item>> eves(N+1);
    for (int id = 1; id <= Q; ++id){
        int a, b, c; cin >> a >> b >> c;
        int l = lca(a, b);
        ans[id] += dep[a] + dep[b] - 2*dep[l] + 1;
        if (c <= B){
            ans[id] += smol[a][c];
            ans[id] += smol[b][c];
            ans[id] -= 2*smol[l][c];
        }
        else{
            eves[a].push_back({id, 1, c});
            eves[b].push_back({id, 1, c});
            eves[l].push_back({id, -2, c});
        }
    }

    using pii = pair<int, int>;
    Tree<pii> bbst;
    auto collect = [&](auto self, int v, int p) -> void{
        for (auto [id, f, c] : eves[v]){
            // if (id == 1){
            //     cout << v << " -> ";
            //     for (auto [x, y] : bbst) cout << x << " ";
            //     cout << '\n';
            // }
            for (int i = 1; i * c <= MW; ++i){
                int cnt = bbst.order_of_key({i*c+c-1, 1e9});
                cnt -= bbst.order_of_key({i*c, -1});
                // if (id == 1) cout << v << " " << cnt << " | ";
                ans[id] += f * i * cnt;
            }
        }
        for (auto [to, w] : adj[v]){
            if (to == p) continue;
            bbst.insert({w, v});
            self(self, to, v);
            bbst.erase({w, v});
        }
    };
    collect(collect, 1, 1);

    for (int id = 1; id <= Q; ++id){
        cout << ans[id] << '\n';
    }
}
