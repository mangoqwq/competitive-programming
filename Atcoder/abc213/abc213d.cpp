#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 +  1;

bool vis[MN];
set<int> adj[MN];
vector<int> ans;

void dfs(int v, int p){
    vis[v] = 1;
    ans.push_back(v);
    while (!adj[v].empty()){
        int to = *adj[v].begin();
        adj[v].erase(to);
        if (vis[to]) continue;
        dfs(to, v);
        ans.push_back(v);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i < N; ++i){
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    dfs(1, 1);
    for (int x : ans) cout << x << " ";
    cout << '\n';
}
