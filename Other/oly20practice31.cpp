#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+2;

int dp[MAXN];
struct Task{
    int s, v;
};
vector<Task> q[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, r; cin >> n >> m >> r; n++;
    for (int i=1;i<=m;++i){
        int s, e, v; cin >> s >> e >> v; s++, e++;
        q[min(n,e+r)].push_back({s,v});
    }
    for (int i=1;i<=n;++i){
        dp[i]=dp[i-1];
        for (Task x:q[i]){
            dp[i]=max(dp[i],dp[x.s]+x.v);
        } 
    }
    cout << dp[n] << '\n';
}