#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int dp[MN][2];
int matching, ans;
vector<int> adj[MN];
map<int, int> val0[MN], val1[MN];

void dfs(int v, int p){
    int cnt = 0;
    for (int to : adj[v]){
        if (to == p) continue;
        dfs(to, v);
        dp[v][0] += dp[to][1];
        if (cnt == -1) continue;
        if (dp[to][0] == dp[to][1]){
            if (cnt) cnt = -1;
            else cnt = to;
        }
    }
    dp[v][1] = dp[v][0] + (cnt != 0);

    for (int to : adj[v]){
        if (to == p) continue;

        val0[v][to] = dp[v][0] - dp[to][1];

        if (cnt == to) val1[v][to] = dp[v][1] - dp[to][1] - 1;
        else val1[v][to] = dp[v][1] - dp[to][1];
    }
}

void reroot(int v, int p, int add, int up0, int up1){
// cout << "-> " << v << " : " << add << " " << dp[v][0] << '\n';
    if (add + dp[v][0] == matching) ans++;
    for (int to : adj[v]){
        if (to == p) continue;
        int tmp = max(up1 + val1[v][to], up0 + 1 + val0[v][to]);
        if (v == 1) tmp = max(up1 + val1[v][to], val0[v][to]);
        reroot(to, v, tmp, up1 + val0[v][to], tmp);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i < N; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1);
    matching = dp[1][1];
    reroot(1, 1, 0, 0, 0);
    cout << ans << '\n';
}
