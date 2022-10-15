#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 100;

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
struct Hallway{ int a, b, c; };
vector<Hallway> h, v;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if (x2 < x1) swap(x1, x2);
        if (y2 < y1) swap(y1, y2);
        if (y1 == y2) h.push_back({x1, x2, y1});
        if (x1 == x2) v.push_back({y1, y2, x1});
    }
    int A = h.size(), B = v.size(), s = N, t = N + 1;
    Dinic g(t);
    for (int i = 0; i < A; ++i) g.add_edge(s, i, 1);
    for (int i = 0; i < B; ++i) g.add_edge(i + A, t, 1);
    for (int i = 0; i < A; ++i){
        for (int j = 0; j < B; ++j){
            if (h[i].a <= v[j].c && h[i].b >= v[j].c && v[j].a <= h[i].c && v[j].b >= h[i].c){
                g.add_edge(i, A + j, 1);
            }
        }
    }
    cout << N - g.max_flow(s, t) << '\n';
}
