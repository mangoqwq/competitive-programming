#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2005;

struct Item{
    int x, l, r;
}; vector<Item> adj[MAXN];
double dp[MAXN][MAXN]; // time, station

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, t; cin >> n >> m >> t;
    for (int i=1;i<=m;++i){
        int a, b, c, d; cin >> a >> b >> c >> d;
        adj[a].push_back({b,c,d});
    }
    dp[0][1]=1;
    for (int i=0;i<=t;++i){
        for (int v=1;v<n;++v){
            if (i>1) dp[i][v]+=dp[i-1][v];
            for (Item a:adj[v]){
                if (i+a.l<=t) dp[i+a.l][a.x]+=dp[i][v]/adj[v].size()/(a.r-a.l+1);
                if (i+a.r+1<=t) dp[i+a.r+1][a.x]-=dp[i][v]/adj[v].size()/(a.r-a.l+1);
            }
        }
    }
    double ans=0, tot=0;
    for (int i=1;i<=t;++i) dp[i][n]+=dp[i-1][n], tot+=dp[i][n];
    for (int i=1;i<=t;++i) ans+=i*dp[i][n]/tot;
    cout << fixed << setprecision(7) << ans << '\n';
}