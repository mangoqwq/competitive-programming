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
    vector<int> ans(N + 1), down(N + 1);
    vector<vector<int>> pre(N + 1), suf(N + 1);
    function<int(int, int)> dfs = [&](int v, int p){
        for (int to : adj[v]){
            if (to == p) continue;
            down[v] = max(down[v], dfs(to, v) + 1);
            pre[v].push_back(down[to]);
            suf[v].push_back(down[to]);
        }
        for (int i = 1; i < pre[v].size(); ++i){
            pre[v][i] = max(pre[v][i], pre[v][i - 1]);
        }
        for (int i = suf[v].size() - 2; i >= 0; --i){
            suf[v][i] = max(suf[v][i], suf[v][i + 1]);
        }
        return down[v];
    }; dfs(1, 1);
    function<void(int, int, int)> go = [&](int v, int p, int up){
        ans[v] = max(down[v], up);
        int idx = 0;
        for (int to : adj[v]){
            if (to == p) continue;
            int nup = up;
            if (idx != 0) nup = max(nup, pre[v][idx - 1] + 1);
            if (idx != suf[v].size() - 1) nup = max(nup, suf[v][idx + 1] + 1);
            go(to, v, nup + 1);
            idx++;
        }
    };
    go(1, 1, 0);
    for (int i = 1; i <= N; ++i) cout << ans[i] << " ";
    cout << '\n';
}
