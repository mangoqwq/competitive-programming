#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        vector<vector<int>> adj(N);
        for (int i = 0; i < M; ++i){
            int a, b; cin >> a >> b;
            a--, b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        using pii = pair<int, int>;
        vector<pii> ans;
        bool bridge = 0;

        vector<int> in(N, -1), up(N);
        int T = 0;
        auto dfs = [&](auto self, int v, int p) -> void{
            in[v] = up[v] = T++;
            for (int to : adj[v]){
                if (to == p) continue;
                if (in[to] == -1){
                    self(self, to, v);
                    up[v] = min(up[v], up[to]);
                    ans.push_back({v, to});
                }
                else if (in[to] < in[v]){
                    up[v] = min(up[v], in[to]);
                    ans.push_back({v, to});
                }
            }
            if (in[v] == up[v] && v != 0){
                bridge = 1;
            }
        };
        dfs(dfs, 0, 0);

        if (bridge) cout << "NO" << '\n';
        else{
            cout << "YES" << '\n';
            for (auto [a, b] : ans){
                cout << a+1 << " " << b+1 << '\n';
            }
        }
    }
}
