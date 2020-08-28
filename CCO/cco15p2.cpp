#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define isset(x,idx) (x&(1<<idx))!=0
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=19,L=1<<18;

struct Edge{int n,w;};
vector<Edge> graph[18];
int dp[L+1][18];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    ms(dp,-1);
    int n,m; cin >> n >> m;
    for (int i=0,a,b,w;i<m;++i){
        cin >> a >> b >> w;
        graph[a].push_back({b,w});
    }
    dp[1][0]=0;
    int ans=0;
    for (int curr=1;curr<=(1<<n);++curr){
        for (int i=0;i<n;++i){
            if (dp[curr][i]==-1) continue;
            for (Edge x:graph[i]){
                if (isset(curr,x.n)) continue;
                dp[(curr|(1<<x.n))][x.n]=max(dp[(curr|(1<<x.n))][x.n],dp[curr][i]+x.w);
            }
            if (i==n-1) ans=max(ans,dp[curr][i]);
        }
    }
    cout << ans << '\n';
}