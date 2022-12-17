#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, D; cin >> N >> D;
    vector<vector<int>> adj(N);
    for (int i = 0; i < N-1; ++i){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    set<int> a, b;
    int na, nb;
    cin >> na;
    for (int i = 0; i < na; ++i){
        int v; cin >> v; v--;
        a.insert(v);
    }
    cin >> nb;
    for (int i = 0; i < nb; ++i){
        int v; cin >> v; v--;
        b.insert(v);
    }

    vector<int> cur;
    auto dfs = [&](auto self, int v, int p) -> void{
        cur.push_back(v);
        if (cur.size() > D){
            int up = cur[cur.size()-D-1];
            if (a.count(v)) b.insert(up);
            if (b.count(v)) a.insert(up);
        }
        for (int to : adj[v]){
            if (to == p) continue;
            self(self, to, v);
        }
        cur.pop_back();
    };
    dfs(dfs, 0, 0);

    auto go = [&](set<int> s){
        int ret = 0;
        auto solve = [&](auto self, int v, int p) -> int{
            int tot = s.count(v);
            for (int to : adj[v]){
                if (to == p) continue;
                tot += self(self, to, v);
            }
            if (tot) ret++;
            return tot;
        };
        solve(solve, 0, 0);
        return ret*2 - 2;
    };

    // for (int x : a) cout << x << " ";
    // cout << '\n';
    // for (int y : b) cout << y << " ";
    // cout << '\n';

    cout << go(a) + go(b) << '\n';
}
