#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int all = (1 << N) - 1;
    vector<set<int>> adj(1 << N);
    for (int i = 0; i < (1 << N); ++i){
        int a = (i << 1) & all;
        if (a != i){
            adj[i].insert(a);
        }
        int b = a + 1;
        if (b != i){
            adj[i].insert(b);
        }
    }
    vector<int> ans;
    vector<bool> vis(1 << N);
    bool found = 0;
    function<void(int)> dfs = [&](int v){
        ans.push_back(v);
        vis[v] = 1;
        if (ans.size() == (1 << N)){
            found = 1;
            return;
        }
        for (int to : adj[v]){
            if (vis[to]) continue;
            dfs(to);
            if (found) return;
        }
        ans.pop_back();
        vis[v] = 0;
    }; dfs(0);
    for (int i = N - 1; i > 0; --i) cout << (ans[0] & (1 << i));
    for (int i = 0; i < (1 << N); ++i) cout << (ans[i] & 1);
    cout << '\n';
}
