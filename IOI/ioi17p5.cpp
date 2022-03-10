#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 500;

#ifndef ONLINE_JUDGE
int count_common_roads(vector<int> &r);
#endif

int N, M;
vector<int> A, B;
vector<int> royal;
vector<int> span;
vector<int> vis;
map<pair<int, int>, int> id_lookup;
struct DisjointSet{
    vector<int> p, sz;
    DisjointSet(int n){
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.resize(n, 1);
    }
    int Find(int x){ return p[x] == x ? x : p[x] = Find(p[x]); }
    bool Union(int a, int b){
        a = Find(a), b = Find(b);
        if (a == b) return 0;
        if (sz[b] > sz[a]) swap(a, b);
        p[b] = a; sz[a] += sz[b];
        return 1;
    }
};

int complete_forest(vector<int> &e){
    DisjointSet dsu(N);
    for (int i : e) dsu.Union(A[i], B[i]);
    int sub = 0;
    for (int i : span){
        if (dsu.Union(A[i], B[i])){
            if (royal[i] == 1) sub++;
            e.push_back(i);
        }
    }
    return sub;
}

int count_common_roads_forest(vector<int> e){
    int sub = complete_forest(e);
    return count_common_roads(e) - sub;
}

void dfs1(int v){
    vis[v] = 1;
    for (int i = 0; i < M; ++i){
        if (A[i] != v && B[i] != v) continue;
        int to = A[i] ^ B[i] ^ v;
        if (vis[to]) continue;
        span.push_back(i);
        dfs1(to);
    }
}

vector<int> stk;
int tin[MN], T;
void dfs2(int v, int p){
    stk.push_back(v);
    vis[v] = 1;
    tin[v] = ++T;
    int up = -1;
    for (int i = 0; i < M; ++i){
        if (A[i] != v && B[i] != v) continue;
        int to = A[i] ^ B[i] ^ v;
        if (to == p || vis[to] == 2) continue;
        if (vis[to] == 1){
            if (up == -1 || tin[to] < tin[up]) up = to;
            continue;
        }
        dfs2(to, v);
    }
    if (up == -1){
        vis[v] = 2;
        stk.pop_back();
        return;
    }
    vector<int> e;
    for (int i = stk.size() - 1; ; --i){
        e.push_back(id_lookup[{stk[i], stk[i - 1]}]);
        if (stk[i - 1] == up) break;
    }
    int mn, mx; mn = mx = count_common_roads_forest(e);
    queue<int> vals;
    e.push_back(id_lookup[{v, up}]);
    bool flag = 0;
    for (int i = stk.size() - 1; ; --i){
        int id = id_lookup[{stk[i], stk[i - 1]}];

        e.erase(e.begin());
        if (royal[id] != 0 && !flag){
            int val = count_common_roads_forest(e);
            if (royal[id] == 1) val++;
            if (val == 0) mn = val;
            else mn = val - 1;
            mx = val;
            flag = 1;
        }

        if (royal[id] == 0){
            int val = count_common_roads_forest(e);
            mn = min(mn, val); mx = max(mx, val);
            vals.push(val);
        }
        e.push_back(id);
        if (stk[i - 1] == up) break;
    }
    for (int i = stk.size() - 1; ; --i){
        int id = id_lookup[{stk[i], stk[i - 1]}];
        if (royal[id] == 0){
            int cur = vals.front(); vals.pop();
            if (mn == mx) royal[id] = -1;
            else{
                if (cur == mn) royal[id] = 1;
                else royal[id] = -1;
            }
        }
        if (stk[i - 1] == up) break;
    }
    vis[v] = 2;
    stk.pop_back();
}

void build_span(){
    dfs1(0);
    fill(vis.begin(), vis.end(), 0);
    dfs2(0, 0);

    for (int i = 0; i < N - 1; ++i){
        if (royal[span[i]] == 0) royal[span[i]] = 1;
    }
}

vector<int> find_degrees(){
    vector<int> degree(N);
    for (int i = 0; i < N; ++i){
        vector<int> e;
        for (int j = 0; j < M; ++j){
            if (A[j] == i || B[j] == i){
                e.push_back(j);
            }
        }
        degree[i] = count_common_roads_forest(e);
    }
    return degree;
}

int solve(vector<int> &e, int l, int r){
    if (l + 1 == r) return e[l];

    int mid = (l + r) >> 1;
    vector<int> left_edges;
    for (int i = l; i < mid; ++i) left_edges.push_back(e[i]);

    if (count_common_roads_forest(left_edges) == 1) return solve(e, l, mid);
    else return solve(e, mid, r);
}

vector<int> find_roads(int n, vector<int> a, vector<int> b){
    if (n == 2) return {0};
    N = n; M = a.size();
    A = a, B = b;
    for (int i = 0; i < M; ++i){
        id_lookup[{A[i], B[i]}] = i;
        id_lookup[{B[i], A[i]}] = i;
    }
    royal.resize(M);
    vis.resize(N);

    build_span();
    vector<int> degree = find_degrees();

    queue<int> q;
    for (int i = 0; i < N; ++i){
        if (degree[i] == 1) q.push(i);
    }
    vis = vector<int>(N, 0);
    while (!q.empty()){
        if (q.size() == 1) break;
        int v = q.front(); q.pop();
        vis[v] = 1;
        vector<int> e;
        for (int i = 0; i < M; ++i){
            if (A[i] != v && B[i] != v) continue;
            int to = A[i] ^ B[i] ^ v;
            if (vis[to]) continue;
            e.push_back(i);
        }
        int good_id = solve(e, 0, e.size());
        for (int i = 0; i < e.size(); ++i){
            if (e[i] == good_id){
                royal[e[i]] = 1;
                int to = A[e[i]] ^ B[e[i]] ^ v;
                degree[to]--;
                if (degree[to] == 1) q.push(to);
            }
            else royal[e[i]] = -1;
        }
    }

    vector<int> ans;
    for (int i = 0; i < M; ++i){
        if (royal[i] == 1) ans.push_back(i);
    }

    return ans;
}
