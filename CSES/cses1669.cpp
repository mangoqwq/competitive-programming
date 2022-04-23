#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

vector<int> adj[MN];
bool vis[MN]; int lst[MN];
void dfs(int v, int p){
    vis[v] = 1;
    for (int to : adj[v]){
        if (to == p) continue;
        if (vis[to]){
            vector<int> ans = {to, v};
            while (true){
                v = lst[v];
                ans.push_back(v);
                if (v == to) break;
            }
            cout << ans.size() << '\n';
            for (int x : ans) cout << x << " ";
            exit(0);
        }
        lst[to] = v;
        dfs(to, v);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i){
        if (!vis[i]){
            dfs(i, i);
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
