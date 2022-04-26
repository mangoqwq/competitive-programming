#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<set<int>> adj(N + 1);
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    for (int i = 1; i <= N; ++i){
        if (adj[i].size() % 2){
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }
    vector<int> ans;
    function<void(int)> dfs = [&](int v){
        while (!adj[v].empty()){
            int to = *adj[v].begin();
            adj[v].erase(to);
            adj[to].erase(v);
            dfs(to);
        }
        ans.push_back(v);
    }; dfs(1);
    if (ans.size() != M + 1 || ans[0] != 1 || ans.back() != 1){
        cout << "IMPOSSIBLE" << '\n';
    }
    else{
        for (int x : ans) cout << x << " ";
        cout << '\n';
    }
}
