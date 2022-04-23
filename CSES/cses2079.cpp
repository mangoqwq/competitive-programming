#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
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
    getsz(1, 1);
    function<int(int, int, int)> findcen = [&](int v, int p, int src) -> int{
        for (int to : adj[v]){
            if (to == p || marked[to]) continue;
            if (sz[to] * 2 > sz[src]) return findcen(to, v, src);
        }
        return v;
    };
    cout << findcen(1, 1, 1) << '\n';
}
