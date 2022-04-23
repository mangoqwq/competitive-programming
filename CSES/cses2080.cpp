#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, L, R; cin >> N >> L; R = L;
    vector<vector<int>> adj(N + 1);
    for (int i = 1; i < N; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> sz(N + 1), marked(N + 1);
    function<int(int, int)> getsz = [&](int v, int p) -> int{
        sz[v] = 1;
        for (int to : adj[v]){
            if (to == p || marked[to]) continue;
            sz[v] += getsz(to, v);
        }
        return sz[v];
    };
    function<int(int, int, int)> findcen = [&](int v, int p, int src) -> int{
        for (int to : adj[v]){
            if (to == p || marked[to]) continue;
            if (sz[to] * 2 > sz[src]) return findcen(to, v, src);
        }
        return v;
    };
    struct Fenwick{
        vector<ll> a;
        vector<int> hist;
        Fenwick(int N){ a = vector<ll>(N); }
        void ins(int i, ll val){
            hist.push_back(i);
            for (; i < a.size(); i += i & -i) a[i] += val;
        }
        ll qry(int i){
            if (i == -1) return 0;
            ll ret = 0;
            for (; i; i -= i & -i) ret += a[i];
            return ret;
        }
        ll qry(int l, int r){
            return qry(r) - qry(l - 1);
        }
        void reset(){
            for (int i : hist){
                for (; i < a.size(); i += i & -i) a[i] = 0;
            }
            hist.clear();
        }
    } bit(N + 1);
    ll ans = 0;
    function<void(int, int, int, vector<int>&)> dfs = [&](int v, int p, int d, vector<int> &dists){
        if (d > R) return;
        if (d >= L) ans++;
        dists.push_back(d);
        for (int to : adj[v]){
            if (to == p || marked[to]) continue;
            dfs(to, v, d + 1, dists);
        }
    };
    function<void(int)> decomp = [&](int v){
        marked[v] = 1;
        for (int to : adj[v]){
            if (marked[to]) continue;
            vector<int> dists;
            dfs(to, v, 1, dists);
            for (int d : dists){
                ans += bit.qry(max(0, L - d), R - d);
            }
            for (int d : dists){
                bit.ins(d, 1);
            }
        }
        bit.reset();
        for (int to : adj[v]){
            if (marked[to]) continue;
            getsz(to, to); decomp(findcen(to, to, to));
        }
    };
    getsz(1, 1); decomp(findcen(1, 1, 1));
    cout << ans << '\n';
}
