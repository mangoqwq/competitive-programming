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
    for (int i = 1; i <= N - 1; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> dist(N + 1, 1e9);
    int far = 1;
    function<void(int, int, int)> dfs = [&](int v, int p, int d){
        dist[v] = d;
        if (d > dist[far]) far = v;
        for (int to : adj[v]){
            if (to == p) continue;
            dfs(to, v, d + 1);
        }
    };
    dfs(1, 1, 0);
    dist = vector<int>(N + 1, 1e9);
    dfs(far, far, 0);
    cout << dist[far] << '\n';
}
