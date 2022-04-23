#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

vector<int> adj[MN];
int vis[MN], in[MN], up[MN], T;

void dfs(int v){
    vis[v] = 1;
    in[v] = up[v] = ++T;
    for (int to : adj[v]){
        if (vis[to] == 2) continue;
        if (vis[to] == 1) up[v] = min(up[v], in[to]);
        else{
            dfs(to);
            up[v] = min(up[v], up[to]);
        }
    }
    if (v != 1 && up[v] == in[v]){
        cout << "NO" << '\n';
        cout << v << " " << 1 << '\n';
        exit(0);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    dfs(1);
    for (int i = 1; i <= N; ++i){
        if (!vis[i]){
            cout << "NO" << '\n';
            cout << 1 << " " << i << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
}
