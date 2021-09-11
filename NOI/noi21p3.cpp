#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 3e5 + 1;

int n, m, q, k, src;
vector<int> adj0[MN], adj[MN];
set<int> adjs[MN];
int sz[MN], dist[MN], scc[MN], T, sccs, vis[MN], low[MN], in[MN], out[MN], deg[MN];
stack<int> stk;

void tarjan(int v){
    in[v] = low[v] = ++T;
    vis[v] = 1;
    stk.push(v);
    for (int to : adj0[v]){
        if (vis[to] == 0){
            tarjan(to);
            low[v] = min(low[v], low[to]);
        }
        else if (vis[to] == 1){
            low[v] = min(low[v], in[to]);
        }
    }
    if (in[v] == low[v]){
        sccs++;
        while (true){
            int x = stk.top(); stk.pop();
            vis[x] = 2; scc[x] = sccs;
            sz[sccs]++;
            if (x == v) break;
        }
    }
}

void build_tree(){
    for (int i = 1; i <= n; ++i){
        for (int to : adj0[i]){
            if (scc[i] != scc[to]){
                adjs[scc[i]].insert(scc[to]);
            }
        }
    }
    for (int i = 1; i <= sccs; ++i){
        for (int to : adjs[i]) deg[to]++;
    }
    queue<int> q;
    for (int i = 1; i <= sccs; ++i){
        if (deg[i] == 0){
            src = i;
            q.push(i);
        }
    }
    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int to : adjs[v]){
            deg[to]--;
            if (deg[to] == 0){
                adj[v].push_back(to);
                q.push(to);
            }
        }
    }
}

bool is_anc(int a, int b){
    return in[a] <= in[b] && out[a] >= out[b];
}

int csz[MN], head[MN], heavy[MN], par[MN], dep[MN], ord[MN], psa[MN];
int eve[20 * MN];

void dfs0(int v){
    csz[v] = 1;
    for (int to : adj[v]){
        par[to] = v;
        dep[to] = dep[v] + 1;
        dfs0(to);
        csz[v] += csz[to];
        if (csz[to] > csz[heavy[v]]) heavy[v] = to;
    }
}

void dfs1(int v, int h){
    head[v] = h; in[v] = ++T; ord[T] = v;
    if (heavy[v]) dfs1(heavy[v], h);
    for (int to : adj[v]){
        if (to == heavy[v]) continue;
        dfs1(to, to);
    }
    out[v] = T;
}

void paint(int a, int b){
    if (!is_anc(a, b)) swap(a, b);
    assert(is_anc(a, b));
    while (head[b] != head[a]){
        eve[++T] = in[head[b]];
        eve[++T] = -in[b];
        b = par[head[b]];
    }
    eve[++T] = in[a];
    eve[++T] = -in[b];
}

struct Road{ int a, b; };
void calc(int s, int t, vector<Road> qs){
    int v = s;
    qs.push_back({t, 0});
    for (auto [a, b] : qs){
        if (!is_anc(v, a)) return;
        v = b;
    }
    v = s;
    for (auto [a, b] : qs){
        paint(v, a);
        v = b;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
#ifndef ONLINE_JUDGE
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
#endif
    cin >> n >> m >> q >> k;
    assert(k <= 2);
    for (int i = 1; i <= m; ++i){
        int a, b; cin >> a >> b;
        adj0[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i){
        if (!vis[i]) tarjan(i);
    }
    build_tree();
    T = 0;
    dfs0(src); dfs1(src, src);
    for (int i = 1; i <= sccs; ++i) psa[i] = psa[i - 1] + sz[ord[i]];
    T = 0;
    for (int i = 1; i <= q; ++i){
        int s, t; Road a, b;
        cin >> s >> t;
        s = scc[s]; t = scc[t];
        if (k >= 1) cin >> a.a >> a.b, a.a = scc[a.a], a.b = scc[a.b];
        if (k >= 2) cin >> b.a >> b.b, b.a = scc[b.a], b.b = scc[b.b];
        if (k >= 0){
            calc(s, t, {});
        }
        if (k >= 1){
            calc(s, t, {a});
            calc(s, t, {a, a});
        }
        if (k >= 2){
            calc(s, t, {a, b});
            calc(s, t, {b, a});
            calc(s, t, {b, b, a});
            calc(s, t, {a, a, b});
            calc(s, t, {a, b, b});
            calc(s, t, {b, a, a});
            calc(s, t, {a, b, a});
            calc(s, t, {b, a, b});
            calc(s, t, {a, a, b, b});
            calc(s, t, {b, b, a, a});
            calc(s, t, {a, b, a, b});
            calc(s, t, {b, a, b, a});
            calc(s, t, {a, b, b, a});
            calc(s, t, {b, a, a, b});
            calc(s, t, {b});
            calc(s, t, {b, b});
        }
        sort(eve + 1, eve + 1 + T, [](int a, int b){ return make_pair(abs(a), -a) < make_pair(abs(b), -b); });
        int cur = 0, lst = 0, ans = 0;
        for (int i = 1; i <= T; ++i){
            int v = abs(eve[i]);
            bool ins = (eve[i] > 0);
            if (ins){
                if (cur == 0) lst = v;
                cur++;
            }
            else{
                cur--;
                if (cur == 0) ans += psa[v] - psa[lst - 1];
            }
        }
        cout << ans << '\n';
        T = 0;
    }
}
