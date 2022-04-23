#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

vector<int> adj[MN];
int vis[MN], in[MN], up[MN], T, sccs, ans[MN];
stack<int> stk;

void dfs(int v){
    vis[v] = 1;
    in[v] = up[v] = ++T;
    stk.push(v);
    for (int to : adj[v]){
        if (vis[to] == 2) continue;
        if (vis[to] == 1) up[v] = min(up[v], in[to]);
        else{
            dfs(to);
            up[v] = min(up[v], up[to]);
        }
    }
    if (in[v] == up[v]){
        sccs++;
        while (true){
            int x = stk.top(); stk.pop();
            ans[x] = sccs; vis[x] = 2;
            if (x == v) break;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= N; ++i){
        if (!vis[i]) dfs(i);
    }
    cout << sccs << '\n';
    for (int i = 1; i <= N; ++i){
        cout << ans[i] << (i == N ? '\n' : ' ');
    }
}
