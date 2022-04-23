#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    int L; L = __lg(N);
    vector<vector<int>> adj(N + 1);
    for (int i = 1; i < N; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int T = 0;
    vector<vector<int>> up(N + 1, vector<int>(L + 1));
    vector<int> in(N + 1);
    vector<int> out(N + 1);
    vector<int> dist(N + 1);
    function<void(int, int)> dfs = [&](int v, int p){
        in[v] = ++T;
        up[v][0] = p;
        for (int i = 1; i <= L; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
        for (int to : adj[v]){
            if (to == p) continue;
            dist[to] = dist[v] + 1;
            dfs(to, v);
        }
        out[v] = T;
    };
    dfs(1, 1);
    function<bool(int, int)> is = [&](int a, int b){
        return in[a] <= in[b] && out[a] >= out[b];
    };
    function<int(int, int)> lca = [&](int a, int b){
        if (is(a, b)) return a;
        if (is(b, a)) return b;
        for (int i = L; i >= 0; --i){
            if (!is(up[a][i], b)) a = up[a][i];
        }
        return up[a][0];
    };
    vector<int> val(N + 1), ans(N + 1);
    for (int i = 1; i <= Q; ++i){
        int a, b; cin >> a >> b;
        val[a]++, val[b]++, val[lca(a, b)] -= 2;
        ans[lca(a, b)]++;
    }
    function<int(int, int)> collect = [&](int v, int p){
        ans[v] += val[v];
        for (int to : adj[v]){
            if (to == p) continue;
            ans[v] += collect(to, v);
            val[v] += val[to];
        }
        return val[v];
    };
    collect(1, 1);
    for (int i = 1; i <= N; ++i) cout << ans[i] << " ";
    cout << '\n';
}
