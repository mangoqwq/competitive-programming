#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int MN = 1e5 + 1, inf = 0x3f3f3f3f;
int dp[MN][2], val[MN];
struct Edge{ int to, t; };
vector<Edge> adj[MN];

void dfs(int v){
    int tot0 = 0, tot1 = 0, tot2 = 0;
    for (auto [to, t] : adj[v]){
        dfs(to);
        if (t == 0){
            tot0 += dp[to][0];
            tot1 += dp[to][1];
            tot2 += dp[to][1];
        }
        if (t == 1 || t == 2){
            tot2 = max(tot0 + dp[to][1], tot2 + dp[to][0]);
            if (t == 1) tot0 += dp[to][1];
            if (t == 2) tot0 += dp[to][0];
            tot1 += dp[to][0];
        }
    }
    dp[v][0] = tot1;
    dp[v][1] = max(tot0 + val[v], tot2);
}

int findSample(int n, int confidence[], int host[], int protocol[]){
    for (int i = 0; i < n; ++i) val[i] = confidence[i];
    for (int i = 1; i < n; ++i){
        adj[host[i]].push_back({i, protocol[i]});
    }
    dfs(0);
    return max(dp[0][0], dp[0][1]);
}
