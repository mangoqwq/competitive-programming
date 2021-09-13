#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

struct Dinic{
    const long long flow_inf = 1e18;
    struct Edge{ int to, nxt; long long c, f = 0; };
    int n;
    queue<int> q;
    vector<int> head, level, ptr;
    vector<Edge> adj;
    Dinic(int _n) : n(_n){
        head.resize(n + 1, -1);
        level.resize(n + 1);
        ptr.resize(n + 1);
    }
    void add_edge(int a, int b, long long c){
        adj.push_back({b, head[a], c}), head[a] = adj.size() - 1;
        adj.push_back({a, head[b], 0}), head[b] = adj.size() - 1;
    }
    void bfs(int s){
        fill(level.begin(), level.end(), 0);
        level[s] = 1; q.push(s);
        while (!q.empty()){
            int v = q.front(); q.pop();
            for (int i = head[v]; i != -1; i = adj[i].nxt){
                auto [to, nxt, c, f] = adj[i];
                if (!level[to] && f < c){
                    level[to] = level[v] + 1;
                    q.push(to);
                }
            }
        }
    }
    long long dfs(int v, long long incoming, int t){
        if (incoming == 0) return 0;
        if (v == t) return incoming;
        for (int &i = ptr[v]; i != -1; i = adj[i].nxt){
            auto [to, nxt, c, f] = adj[i];
            if (f == c || level[to] != level[v] + 1) continue;
            long long pushed = dfs(to, min(incoming, c - f), t);
            if (pushed == 0) continue;
            adj[i].f += pushed;
            adj[i ^ 1].f -= pushed;
            return pushed;
        }
        return 0;
    }
    long long max_flow(int s, int t){
        long long ans = 0;
        while (true){
            bfs(s);
            if (!level[t]) break;
            for (int i = 0; i <= n; ++i) ptr[i] = head[i];
            while (long long pushed = dfs(s, flow_inf, t)) ans += pushed;
        }
        return ans;
    }
    bool left_of_cut(int v){ return level[v]; }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    Dinic g(n + m + 1);
    int s = 0, t = n + m + 1;
    for (int i = 1; i <= n; ++i){
        int p; cin >> p;
        g.add_edge(i + m, t, p);
    }
    ll tot = 0;
    for (int i = 1; i <= m; ++i){
        int a, b, c; cin >> a >> b >> c;
        tot += c;
        g.add_edge(i, a + m, inf);
        g.add_edge(i, b + m, inf);
        g.add_edge(s, i, c);
    }
    cout << tot - g.max_flow(s, t) << '\n';
}
