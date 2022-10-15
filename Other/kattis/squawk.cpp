#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101;

vector<int> adj[MAXN];
ll last[MAXN], dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, s, t; cin >> n >> m >> s >> t;
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    } 
    dp[s]=1;
    for (int i=1;i<=t;++i){
        swap(last,dp); ms(dp,0);
        for (int v=0;v<n;++v){
            for (int to:adj[v]){
                dp[to]+=last[v];
            }
        }
    }
    cout << accumulate(dp,dp+n,0LL) << '\n';
}