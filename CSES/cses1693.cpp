#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<multiset<int>> adj(N + 1);
    vector<int> in(N + 1), out(N + 1);
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        out[a]++, in[b]++;
    }
    adj[N].insert(1);
    out[N]++, in[1]++;
    for (int i = 1; i <= N; ++i){
        if (in[i] != out[i]){
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }
    vector<int> ans;
    function<void(int)> dfs = [&](int v){
        while (!adj[v].empty()){
            int to = *adj[v].begin();
            adj[v].erase(adj[v].find(to));
            dfs(to);
        }
        ans.push_back(v);
    }; dfs(1);
    if (ans.size() != M + 2){
        cout << "IMPOSSIBLE" << '\n';
    }
    else{
        reverse(ans.begin(), ans.end());
        ans.pop_back();
        for (int i = 0; i < ans.size() - 1; ++i){
            if (ans[i] == N && ans[i + 1] == 1){
                rotate(ans.begin(), ans.begin() + i + 1, ans.end());
                break;
            }
        }
        for (int x : ans) cout << x << " ";
        cout << '\n';
    }
}
