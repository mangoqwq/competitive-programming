#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> a(N + 1);
    vector<vector<int>> adj(N + 1);
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    for (int i = 1; i < N; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<set<int>> c(N + 1);
    vector<int> ans(N + 1);
    function<void(int, int)> dfs = [&](int v, int p){
        c[v].insert(a[v]);
        for (int to : adj[v]){
            if (to == p) continue;
            dfs(to, v);
            if (c[to].size() > c[v].size()) swap(c[to], c[v]);
            for (int x : c[to]) c[v].insert(x);
        }
        ans[v] = c[v].size();
    }; dfs(1, 1);
    for (int i = 1; i <= N; ++i) cout << ans[i] << " ";
    cout << '\n';
}
