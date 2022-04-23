#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

vector<int> adj[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 2; i <= N; ++i){
        int p; cin >> p;
        adj[p].push_back(i);
    }
    vector<int> sz(N + 1, 0);
    function<int(int)> dfs = [&](int v) -> int{
        sz[v] = 1;
        for (int to : adj[v]) sz[v] += dfs(to);
        return sz[v];
    };
    dfs(1);
    for (int i = 1; i <= N; ++i) cout << sz[i] - 1 << " ";
    cout << '\n';
}
