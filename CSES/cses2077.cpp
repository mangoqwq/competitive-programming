#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> in(N + 1), up(N + 1);
    int T = 0;
    set<int> art;
    function<void(int, int)> dfs = [&](int v, int p){
        in[v] = up[v] = ++T;
        int c = 0;
        for (int to : adj[v]){
            if (to == p) continue;
            if (!in[to]){
                c++;
                dfs(to, v);
                up[v] = min(up[v], up[to]);
                if (v != p && up[to] >= in[v]) art.insert(v);
            }
            else up[v] = min(up[v], in[to]);
        }
        if (v == p && c > 1) art.insert(v);
    }; dfs(1, 1);
    cout << art.size() << '\n';
    for (int x : art) cout << x << " ";
}
