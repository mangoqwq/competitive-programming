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
    vector<pair<int, int>> get_matching(){
        vector<pair<int, int>> ret;
        for (int i = 0; i < adj.size(); i += 2){
            int a = adj[i + 1].to;
            int b = adj[i + 0].to;
            if (a == 0 || b == n) continue;
            if (adj[i].f) ret.push_back({a, b});
        }
        return ret;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    Dinic g(n + m + 1);
    for (int i = 1; i <= n; ++i) g.add_edge(0, i, 1);
    for (int i = 1; i <= m; ++i) g.add_edge(n + i, n + m + 1, 1);
    vector<pair<int, int>> edges;
    for (int i = 1; i <= k; ++i){
        int a, b; cin >> a >> b;
        g.add_edge(a, n + b, 1);
        edges.push_back({a, b});
    }
    cout << g.max_flow(0, n + m + 1) << '\n';
    for (auto [a, b] : g.get_matching()){
        cout << a << " " << b - n << '\n';
    }
}
