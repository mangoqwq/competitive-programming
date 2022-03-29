#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;

int loop[MN], vis[MN];
vector<int> adj[MN];
int k[MN], val[MN], deg[MN];

void dfs(int v){
    vis[v] = 1;
    for (int to : adj[v]){
        if (vis[to] == 0){
            dfs(to);
            loop[v] |= loop[to];
        }
        else if (vis[to] == 1){
            loop[v] = 1;
        }
        else if (vis[to] == 2){
            loop[v] |= loop[to];
        }
    }
    vis[v] = 2;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> k[i];
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= N; ++i){
        if (!vis[i]) dfs(i);
        if (loop[i] && k[i] == 1){
            cout << -1 << '\n';
            exit(0);
        }
        if (!loop[i]){
            for (int to : adj[i]) deg[to]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= N; ++i){
        if (loop[i]) continue;
        if (deg[i] == 0) q.push(i);
    }
    int ans = 0;
    while (!q.empty()){
        int v = q.front(); q.pop();
        if ((k[v] ^ val[v]) == 1){
            val[v] ^= 1;
            ans++;
        }
        for (int to : adj[v]){
            val[to] ^= val[v];
            deg[to]--;
            if (deg[to] == 0) q.push(to);
        }
    }
    cout << ans << '\n';
}
