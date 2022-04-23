#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int to[MN], vis[MN], ans[MN], T;

void dfs(int v){
    if (ans[v]) return;
    vis[v] = ++T;
    if (vis[to[v]] > 0){
        int len = vis[v] - vis[to[v]] + 1;
        ans[v] = len;
        for (int x = to[v]; x != v; x = to[x]) ans[x] = len;
    }
    else{
        if (!vis[to[v]]) dfs(to[v]);
        if (!ans[v]) ans[v] = ans[to[v]] + 1;
    }
    vis[v] = -1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> to[i];
    }
    for (int i = 1; i <= N; ++i){
        dfs(i);
        cout << ans[i] << (i == N ? '\n' : ' ');
    }
}
