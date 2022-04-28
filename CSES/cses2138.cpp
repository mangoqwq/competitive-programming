#include <bits/stdc++.h>
#pragma GCC target("popcnt")

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    const int MN = 5e4;
    int N, M; cin >> N >> M;
    vector<bitset<MN>> ans(N);
    vector<vector<int>> adj(N), rev(N);
    vector<int> deg(N);
    for (int i = 0; i < M; ++i){
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        rev[b].push_back(a);
        deg[a]++;
    }
    queue<int> q;
    for (int i = 0; i < N; ++i){
        ans[i][i] = 1;
        if (!deg[i]) q.push(i);
    }
    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int to : adj[v]){
            ans[v] |= ans[to];
        }
        for (int to : rev[v]){
            deg[to]--;
            if (deg[to] == 0) q.push(to);
        }
    }
    for (int i = 0; i < N; ++i) cout << ans[i].count() << " ";
    cout << '\n';
}
