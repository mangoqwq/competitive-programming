#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, S; cin >> N >> M >> S;
    vector<set<int>> adj(N+1);
    for (int i = 0; i < M; ++i){
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    vector<int> vis(N+1);
    int T = 0;
    auto dfs = [&](auto self, int v) -> void{
        vis[v] = ++T;
        for (int to : adj[v]){
            if (!vis[to]){
                self(self, to);
            }
        }
    };
    dfs(dfs, S);
    for (int i = 1; i <= N; ++i){
        cout << vis[i] << '\n';
    }
    cout << '\n';
}
