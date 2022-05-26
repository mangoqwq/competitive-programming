#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K, Q; cin >> N >> K >> Q;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i){
        cin >> A[i];
    }

    struct Edge{ int to, t; };
    vector<vector<Edge>> adj(N + 1);
    vector<int> vis(N + 1);
    bool cycle = 0;
    function<void(int, int)> dfs = [&](int v, int val){
        vis[v] = 1;
        for (auto [to, t] : adj[v]){
            if (t > val) continue;
            if (vis[to] == 2) continue;
            if (vis[to] == 1) cycle = 1;
            else dfs(to, val);
        }
        vis[v] = 2;
    };

    vector<vector<int>> can(N + 1, vector<int>(N + 1));
    for (int l = 1; l <= N; ++l){
        for (int i = 1; i <= N; ++i){
            adj[i].clear();
        }

        for (int i = l + 1; i <= N; i += 2){
            adj[A[i]].push_back({A[i - 1], i});
            if (i != N) adj[A[i]].push_back({A[i + 1], i + 1});
        }

        int lo = l, hi = N;
        while (lo < hi){
            int mid = (lo + hi + 1) >> 1;
            cycle = 0;
            fill(vis.begin(), vis.end(), 0);
            for (int i = 1; i <= N; ++i){
                if (!vis[i]) dfs(i, mid);
            }
            if (cycle) hi = mid - 1;
            else lo = mid;
        }
        for (int r = l; r <= lo; ++r){
            can[l][r] = 1;
        }
    }

    while (Q--){
        int l, r; cin >> l >> r;
        if (can[l][r]) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}
