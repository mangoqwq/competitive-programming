#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 250;

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
    int s = 0, t = 17;
    Dinic g(t);
    for (int i = 1; i <= 8; ++i){
        int x; cin >> x;
        g.add_edge(s, i, x);
    }
    for (int i = 9; i <= 16; ++i){
        int x; cin >> x;
        g.add_edge(i, t, x);
    }
    auto connect = [&g](int a, int b){
        g.add_edge(a, b, inf); // - to -
        g.add_edge(a, b + 1, inf); // - to +
        g.add_edge(a + 1, b + 1, inf); // + to +
    };
    connect(1, 9);  // O -> O
    connect(3, 11); // A -> A
    connect(5, 13); // B -> B
    connect(7, 15); // AB -> AB
    connect(1, 11); // O -> A
    connect(1, 13); // O -> B
    connect(1, 15); // O -> AB
    connect(3, 15); // A -> AB
    connect(5, 15); // B -> AB
    cout << g.max_flow(s, t) << '\n';
}
