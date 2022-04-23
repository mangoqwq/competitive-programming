#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

vector<int> adj[MN];
int lst[MN], dist[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ms(dist, 0x3f);
    dist[N] = 0;
    queue<int> q; q.push(N);
    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int to : adj[v]){
            if (dist[to] != inf) continue;
            dist[to] = dist[v] + 1;
            lst[to] = v;
            q.push(to);
        }
    }
    if (dist[1] == inf) cout << "IMPOSSIBLE" << '\n';
    else{
        cout << dist[1] + 1 << '\n';
        int v = 1;
        while (v != N){
            cout << v << " ";
            v = lst[v];
        }
        cout << N << '\n';
    }
}
