#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

ll val[MN], sval[MN], deg[MN], dp[MN];
vector<int> adj[MN], dag[MN], rev[MN], ord, comp, roots;
bool vis[MN];
int root[MN];

void dfs(int v){
    vis[v] = 1;
    for (int to : adj[v]){
        if (vis[to]) continue;
        dfs(to);
    }
    // cout << v << " ";
    ord.push_back(v);
}

void kosaraju(int v){
    comp.push_back(v);
    vis[v] = 1;
    for (int to : rev[v]){
        if (vis[to]) continue;
        kosaraju(to);
    }
}

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> val[i];
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i){
        if (!vis[i]) dfs(i);
    }
    ms(vis, 0);
    reverse(ord.begin(), ord.end());
    for (int v : ord){
        if (!vis[v]){
            kosaraju(v);
            for (int u : comp) root[u] = v, sval[v] += val[u];
            roots.push_back(v);
            comp.clear();
        }
    }
    for (int i = 1; i <= N; ++i){
        for (int to : adj[i]){
            int rt_v = root[i], rt_u = root[to];
            if (rt_v != rt_u){
                dag[rt_v].push_back(rt_u);
                deg[rt_u]++;
            }
        }
    }
    queue<int> q;
    for (int rt : roots){
        if (deg[rt] == 0) q.push(rt), dp[rt] = sval[rt];
    }
    ll ans = 0;
    while (!q.empty()){
        int v = q.front(); q.pop();
        ans = max(ans, dp[v]);
        for (int to : dag[v]){
            dp[to] = max(dp[to], dp[v] + sval[to]);
            deg[to]--;
            if (deg[to] == 0) q.push(to);
        }
    }
    cout << ans << '\n';
}
