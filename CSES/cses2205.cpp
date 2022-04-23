#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = (1 << 16);

int N;
vector<int> adj[MN];
bool vis[MN];
int ord[MN + 1];
void dfs(int i, int v){
    ord[i] = v;
    if (i == (1 << N)){
        for (int i = 1; i <= (1 << N); ++i){
            for (int j = 0; j < N; ++j){
                if (1 & (ord[i] >> j)) cout << 1;
                else cout << 0;
            }
            cout << '\n';
        }
        exit(0);
    }
    vis[v] = 1;
    for (int to : adj[v]){
        if (vis[to]) continue;
        dfs(i + 1, to);
    }
    vis[v] = 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < (1 << N); ++i){
        for (int j = 0; j < N; ++j){
            int to = i ^ (1 << j);
            adj[i].push_back(to);
        }
    }
    dfs(1, 0);
}
