#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 3e5+1;

vector<int> adj[MAXN];
int best[MAXN];

void dfs(int v){
    for (int to : adj[v]){
        if (best[to]) continue;
        best[to] = best[v];
        dfs(to);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int a, b; cin >> a >> b;
        adj[b].push_back(a);
    }
    for (int i = n; i >= 1; --i){
        if (best[i]){
            cout << i << " " << best[i];
            return 0;
        }
        best[i] = i;
        dfs(i);
    }
    cout << -1 << '\n';
}
