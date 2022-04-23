#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<vector<int>> adj(N + 1);
    for (int i = 1; i < N; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> sz(N + 1), tot(N + 1), ans(N + 1);
    function<void(int, int)> dfs = [&](int v, int p){
        sz[v] = 1;
        for (int to : adj[v]){
            if (to == p) continue;
            dfs(to, v);
            sz[v] += sz[to];
            tot[v] += tot[to] + sz[to];
        }
    }; dfs(1, 1);
    function<void(int, int, ll)> go = [&](int v, int p, ll up){
        ans[v] = tot[v] + up;
        for (int to : adj[v]){
            if (to == p) continue;
            ll add = tot[v] + up - tot[to] - sz[to] + (N - sz[to]);
            go(to, v, add);
        }
    }; go(1, 1, 0);
    for (int i = 1; i <= N; ++i) cout << ans[i] << " ";
    cout << '\n';
}
