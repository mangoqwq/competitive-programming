#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int a[MN], vis[MN];
int N, ans = inf;
vector<int> seen;
void dfs(int v, int d = 1){
    vis[v] = d;
    seen.push_back(v);
    if (vis[a[v]] == -1) return;
    if (vis[a[v]] != 0){
        ans = min(ans, d - vis[a[v]] + 1);
        return;
    }
    dfs(a[v], d + 1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= N; ++i){
        if (!vis[i]) dfs(i);
        for (int x : seen) vis[x] = -1;
        seen.clear();
    }
    cout << ans << '\n';
}
