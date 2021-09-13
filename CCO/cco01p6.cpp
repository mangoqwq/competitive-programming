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
    while (true){
        int n, m; cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<int> best(m + 1), worst(m + 1);
        vector<set<int>> states(n + 1);
        for (int i = 1; i <= n; ++i){
            int c; cin >> c;
            for (int j = 1; j <= c; ++j){
                int x; cin >> x;
                best[x]++;
                if (c == 1) worst[x]++;
                states[i].insert(x);
            }
        }
        for (int i = 1; i <= m; ++i){
            cout << "Candidate " << i << " ";
            int best_others = 0;
            for (int j = 1; j <= n; ++j){
                if (i == j) continue;
                best_others = max(best_others, best[j]);
            }
            if (best_others < worst[i]) cout << "will";
            else{
                Dinic g(n + m + 1);
                for (int j = 1; j <= n; ++j) if (!states[j].count(i)) g.add_edge(0, j, 1);
                for (int j = 1; j <= n; ++j){
                    for (int x : states[j]) g.add_edge(j, n + x, 1);
                }
                for (int j = 1; j <= m; ++j) g.add_edge(n + j, n + m + 1, best[i] - 1);
                int votes = g.max_flow(0, n + m + 1);
                if (votes + best[i] >= n) cout << "may";
                else cout << "will not";
            }
            cout << " become president." << '\n';
        }
    }    
}
