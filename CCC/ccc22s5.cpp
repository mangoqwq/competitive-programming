#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

ll dp[MN][3];
bool is[MN]; int a[MN];
vector<int> adj[MN];

void dfs(int v, int p){
    ll sum0 = 0, sum1 = 0, sum2 = 0, mn1 = inf, mn2 = inf;
    for (int to : adj[v]){
        if (to == p) continue;
        dfs(to, v);
        sum0 += dp[to][0];
        sum1 += dp[to][1];
        sum2 += dp[to][2];
        mn1 = min(mn1, -dp[to][1] + dp[to][2]);
        mn2 = min(mn2, -dp[to][0] + dp[to][2] + a[v]);
    }
    if (is[v]){
        dp[v][0] = sum1;
        dp[v][1] = sum1;
        dp[v][2] = sum0 + a[v];
    }
    else{
        dp[v][0] = min(sum0 + a[v], sum1);
        dp[v][1] = sum1 + mn1;
        dp[v][2] = sum0 + mn2;
    }
    dp[v][1] = min(dp[v][1], dp[v][2]);
    dp[v][0] = min(dp[v][0], dp[v][1]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N - 1; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i){
        char c; cin >> c;
        is[i] = c == 'Y';
    }
    for (int i = 1; i <= N; ++i) cin >> a[i];
    dfs(1, 1);
    cout << dp[1][1] << '\n';
}
