#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

int vis[MN];
vector<int> adj[MN];
vector<int> in;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    function<void(int)> dfs = [&](int v){
        vis[v] = 1;
        in.push_back(v);
        for (int to : adj[v]){
            if (vis[to] == 2) continue;
            if (vis[to] == 1){
                int i = find(in.begin(), in.end(), to) - in.begin();
                cout << in.size() - i + 1 << '\n';
                in.push_back(to);
                for (; i < in.size(); ++i){
                    cout << in[i] << " ";
                }
                cout << '\n';
                exit(0);
            }
            dfs(to);
        }
        in.pop_back();
        vis[v] = 2;
    };
    for (int i = 1; i <= N; ++i){
        if (!vis[i]) dfs(i);
    }
    cout << "IMPOSSIBLE" << '\n';
}
