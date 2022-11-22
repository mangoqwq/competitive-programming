#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i){
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    struct Boomer{ int a, b, c; };
    vector<Boomer> ans;
    vector<int> vis(N);
    auto dfs = [&](auto self, int v, int p) -> bool{
        vis[v] = 1;
        vector<int> ups;
        for (int to : adj[v]){
            if (to == p) continue;
            if (vis[to] == 2) continue;
            if (vis[to] == 1){
                ups.push_back(to);
            }
            else{
                if (self(self, to, v)){
                    ups.push_back(to);
                }
            }
        }
        vis[v] = 2;
        while (ups.size() >= 2){
            int a = ups.back(); ups.pop_back();
            int b = ups.back(); ups.pop_back();
            ans.push_back({a, v, b});
        }
        if (ups.empty()){
            return 1;
        }
        else{
            if (v != p) ans.push_back({ups[0], v, p});
            return 0;
        }
    };

    for (int i = 0; i < N; ++i){
        if (!vis[i]) dfs(dfs, i, i);
    }
    cout << ans.size() << '\n';
    for (auto [a, b, c] : ans){
        cout << a+1 << " " << b+1 << " " << c+1 << '\n';
    }
}
