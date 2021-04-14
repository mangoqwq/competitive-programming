#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=301;

vector<int> adj[MAXN];
int n, d, val[MAXN], L;
int last[MAXN][4*MAXN], dp[MAXN][4*MAXN];

int dfs(int v){
    for (int to:adj[v]) val[v]+=dfs(to);
    dp[v][0+L]=0;
    for (int to:adj[v]){
        for (int i=-L;i<=L;++i) last[v][i+L]=dp[v][i+L];
        for (int i=-L;i<=L;++i){
            for (int j=-L;j<=L;++j){
                if (i+j>L||i+j<-L) continue;
                dp[v][i+j+L]=min(dp[v][i+j+L],last[v][i+L]+dp[to][j+L]);
            }
        }
    }
    dp[v][val[v]+L]=min(dp[v][val[v]+L],1);
    return val[v];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> d; L=2*n;
    for (int i=1;i<=n;++i){
        int v, col, c; cin >> v >> col >> c;
        val[v]=col*2-1;
        for (int j=1;j<=c;++j){
            int x; cin >> x;
            adj[v].push_back(x);
        }
    }
    ms(dp,0x3f);
    dfs(0);
    int ans=dp[0][val[0]-d+L];
    cout << (ans==inf?-1:ans) << '\n';
}