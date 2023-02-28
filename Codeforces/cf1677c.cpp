#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }
        vector<int> b(N);
        for (int i = 0; i < N; ++i){
            cin >> b[i];
        }

        vector<vector<int>> adj(N+1);
        for (int i = 0; i < N; ++i){
            adj[a[i]].push_back(b[i]);
            adj[b[i]].push_back(a[i]);
        }

        vector<int> comp;
        vector<int> vis(N+1);
        auto dfs = [&](auto self, int v) -> int{
            int sz = 1;
            vis[v] = 1;
            for (int to : adj[v]){
                if (vis[to]) continue;
                sz += self(self, to);
            }
            return sz;
        };
        int cnt = 0;
        for (int i = 1; i <= N; ++i){
            if (!vis[i]){
                int sz = dfs(dfs, i);
                cnt += sz / 2;
            }
        }

        ll ans = 0;
        for (int i = 1; i <= cnt; ++i){
            ans -= i;
            ans += N-i+1;
        }
        cout << ans*2 << '\n';
    }
}
