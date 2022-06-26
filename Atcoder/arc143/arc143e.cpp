#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<vector<int>> adj(N + 1);
    for (int i = 1; i <= N - 1; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> can(N + 1);
    for (int i = 1; i <= N; ++i){
        char c; cin >> c;
        can[i] = c == 'W';
    }

    vector<int> dp(N + 1);
    vector<vector<int>> dag(N + 1);
    vector<int> deg(N + 1);
    function<void(int, int)> dfs = [&](int v, int p){
        dp[v] = can[v];
        for (int to : adj[v]){
            if (to == p) continue;
            dfs(to, v);
            dp[v] ^= dp[to];
            if (!dp[to]) dag[v].push_back(to), deg[to]++;
            if (dp[to]) dag[to].push_back(v), deg[v]++;
        }
    };
    dfs(1, 1);

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= N; ++i){
        if (!deg[i]) q.push(i);
    }

    vector<int> ans;
    bool bad = 0;
    while (!q.empty()){
        int v = q.top(); q.pop();
        ans.push_back(v);
        if (!can[v]) bad = 1;
        for (int to : adj[v]){
            can[to] = !can[to];
        }
        for (int to : dag[v]){
            deg[to]--;
            if (deg[to] == 0){
                q.push(to);
            }
        }
    }

    if (ans.size() != N){
        bad = 1;
    }
    if (bad) cout << -1 << '\n';
    else{
        for (int x : ans) cout << x << " ";
        cout << '\n';
    }
}
