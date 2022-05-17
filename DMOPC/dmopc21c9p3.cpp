#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    // good problem
    int N, M; cin >> N >> M;
    
    vector<vector<int>> adj(N + 1);
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, 1e9));
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i){

        queue<int> q; q.push(i);
        dist[i][i] = 0;

        while (!q.empty()){
            int v = q.front(); q.pop();
            for (int to : adj[v]){
                if (dist[i][v] + 1 < dist[i][to]){
                    dist[i][to] = dist[i][v] + 1;
                    q.push(to);
                }
            }
        }
    }

    int Q; cin >> Q;
    while (Q--){
        int s, t, x, u, v, y;
        cin >> s >> t >> x;
        cin >> u >> v >> y;
        if (dist[s][t] <= x || dist[u][v] <= y){
            cout << "YES" << '\n';
            continue;
        }
        else if (dist[s][u] + 1 + dist[t][v] + 1 <= x + y){ // u <-> t
            cout << "YES" << '\n';
        }
        else if (dist[s][v] + 1 + dist[u][t] + 1 <= x + y){ // v <-> t
            cout << "YES" << '\n';
        }
        else if (dist[u][t] + 1 + dist[s][v] + 1 <= x + y){ // u <-> s
            cout << "YES" << '\n';
        }
        else if (dist[v][t] + 1 + dist[u][s] + 1 <= x + y){ // v <-> s
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
}
