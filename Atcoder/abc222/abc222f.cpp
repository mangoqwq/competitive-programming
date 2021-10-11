#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

struct Edge{ int to; ll w; };
vector<Edge> adj[MN];
ll ans[MN], cost[MN];
int sz[MN];
bool marked[MN];

void get_sz(int v, int p){
    sz[v] = 1;
    for (auto [to, w] : adj[v]){
        if (to == p || marked[to]) continue;
        get_sz(to, v);
        sz[v] += sz[to];
    }
}

int search_cen(int v, int p, int src){
    for (auto [to, w] : adj[v]){
        if (to == p || marked[to]) continue;
        if (sz[to] * 2 > sz[src]) return search_cen(to, v, src);
    }
    return v;
}

int get_cen(int v){
    get_sz(v, v);
    return search_cen(v, v, v);
}

void dfs(int v, int p, ll d, ll add, ll &mx){
    ans[v] = max(ans[v], d + add);
    mx = max(mx, d + cost[v]);
    for (auto [to, w] : adj[v]){
        if (to == p || marked[to]) continue;
        dfs(to, v, d + w, add, mx);
    }
}

void go(int v){
    v = get_cen(v);
// cout << v << " -> ";

    ll mx = 0, add = cost[v];
    for (auto [to, w] : adj[v]){
        if (marked[to]) continue;
        dfs(to, v, w, add, mx);
        add = max(add, mx);
    }
    ans[v] = max(ans[v], mx);

    mx = 0; add = cost[v];
    reverse(adj[v].begin(), adj[v].end());
    for (auto [to, w] : adj[v]){
        if (marked[to]) continue;
        dfs(to, v, w, add, mx);
        add = max(add, mx);
    }
    ans[v] = max(ans[v], mx);
// cout << add << " ";
// cout << '\n';

    marked[v] = 1;
    for (auto [to, w] : adj[v]){
        if (marked[to]) continue;
        go(to);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i < N; ++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for (int i = 1; i <= N; ++i) cin >> cost[i];
    go(1);
    for (int i = 1; i <= N; ++i){
        cout << ans[i] << '\n';
    }
}
