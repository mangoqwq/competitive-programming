#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=300'001;

vector<int> graph[MAXN];
ll dp[MAXN][2],g[MAXN][2];
bool c[MAXN]; // 0 is blue, 1 is red

void solve(int node, int prev){
    dp[node][0]=1, dp[node][1]=1;
    for (int x:graph[node]){
        if (x==prev) continue;
        solve(x,node);
        dp[node][0]*=1+g[x][0], dp[node][0]%=mod;
        dp[node][1]*=1+g[x][1], dp[node][1]%=mod;
    }
    dp[node][!c[node]]--;
    g[node][0]=dp[node][0], g[node][1]=dp[node][1];
    for (int x:graph[node]){
        if (x==prev) continue;
        dp[node][0]-=g[x][0], dp[node][0]%=mod;
        dp[node][1]-=g[x][1], dp[node][1]%=mod;
    }
    for (int x:graph[node]){
        if (x!=prev) dp[node][c[node]]+=g[x][c[x]];
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    char color;
    for (int i=1;i<=n;++i) cin >> color, c[i]=color=='R';
    for (int i=1,a,b;i<n;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    solve(1,1);
    for (int i=1;i<=n;++i){
        cout << i << " -> " << dp[i][0] << " " << dp[i][1] << " " << g[i][0] << " " << g[i][1] << '\n';
    }    
}