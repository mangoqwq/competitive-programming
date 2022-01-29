#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
using vi = vector<int>;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 10, LG = 17;
vector<int> adj[MN], tree[MN];
int p[MN], up[MN][LG + 1], par[MN];
int x[MN], y[MN], in[MN], out[MN], lx[MN], rx[MN], ly[MN], ry[MN];
int ans[MN], T;
struct Event{
    int x, y, v, id;
    bool operator<(const Event &other){
        return tie(x, y, id) < tie(other.x, other.y, other.id);
    }
};
struct Fenwick{
    int a[MN];
    void ins(int i){ for (++i; i < MN; i += i & -i) a[i]++; }
    int qry(int i){
        int ret = 0;
        for (++i; i; i -= i & -i) ret += a[i];
        return ret;
    }
} bit;
int Find(int x){ return p[x] == x ? x : p[x] = Find(p[x]); }
void dfs(int v){
    in[v] = ++T;
    for (int i = 1; i <= LG; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
    for (int to : tree[v]){
        up[to][0] = v;
        dfs(to);
    }
    out[v] = T;
}
bool anc(int a, int b){ return in[a] <= in[b] && out[a] >= out[b]; }

vi check_validity(int N, vi U, vi V, vi S, vi E, vi L, vi R){
    int M = U.size(), Q = S.size();
    for (int i = 0; i < M; ++i){
        int u = U[i], v = V[i];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < N; ++i) p[i] = i;
    for (int i = N - 1; i >= 0; --i){
        for (int to : adj[i]){
            to = Find(to);
            if (to <= i) continue;
            p[to] = i;
            tree[i].push_back(to);
        }
    }
    dfs(0);
    for (int i = 0; i < N; ++i) x[i] = in[i];
    for (int i = 0; i < Q; ++i){
        int v = S[i];
        for (int j = LG; j >= 0; --j){
            if (up[v][j] >= L[i]) v = up[v][j];
        }
        lx[i] = in[v];
        rx[i] = out[v];
    }
    for (int i = 0; i < N; ++i){
        p[i] = i, tree[i].clear();
        fill(up[i], up[i] + 1 + LG, N - 1);
    }
    for (int i = 0; i < N; ++i){
        for (int to : adj[i]){
            to = Find(to);
            if (to >= i) continue;
            p[to] = i;
            tree[i].push_back(to);
        }
    }
    T = 0;
    dfs(N - 1);
    for (int i = 0; i < N; ++i) y[i] = in[i];
    for (int i = 0; i < Q; ++i){
        int v = E[i];
        for (int j = LG; j >= 0; --j){
            if (up[v][j] <= R[i]) v = up[v][j];
        }
        ly[i] = in[v];
        ry[i] = out[v];
    }
    vector<Event> eves;
    for (int i = 0; i < N; ++i) eves.push_back({x[i], y[i], 0, -1});
    for (int i = 0; i < Q; ++i){
        eves.push_back({lx[i] - 1, ly[i] - 1, 1, i});
        eves.push_back({rx[i], ly[i] - 1, -1, i});
        eves.push_back({lx[i] - 1, ry[i], -1, i});
        eves.push_back({rx[i], ry[i], 1, i});
    }
    sort(eves.begin(), eves.end());
    for (auto [x, y, v, id] : eves){
        if (id == -1){
            bit.ins(y);
        }
        else{
            ans[id] += v * bit.qry(y);
        }
    }
    vector<int> ret(Q);
    for (int i = 0; i < Q; ++i){
        ret[i] = ans[i] != 0;
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("txt.in", "r", stdin);
    int N, M, Q; cin >> N >> M >> Q;
    vi X(M), Y(M);
    for (int i = 0; i < M; ++i){
        cin >> X[i] >> Y[i];
    }
    vi S(Q), E(Q), L(Q), R(Q);
    for (int i = 0; i < Q; ++i){
        cin >> S[i] >> E[i] >> L[i] >> R[i];
    }
    vi ans = check_validity(N, X, Y, S, E, L, R);
    for (int i = 0; i < Q; ++i) cout << ans[i] << " ";
    cout << '\n';
}
