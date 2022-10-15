#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=(1<<18);

vector<int> graph[18];
int dp[MAXN][18];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,m,start,end,v; cin >> n >> m >> start >> end >> v;
    start--; end--;
    for (int i=1,a,b;i<=m;++i){
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ms(dp,-1); dp[(1<<start)][start]=0;
    for (int curr=1;curr<(1<<n);++curr){
        for (int i=0;i<n;++i){
            if (dp[curr][i]==-1||!(1&(curr>>i))) continue;
            for (int x:graph[i]){
                if (1&(curr>>x)) continue;
                dp[curr+(1<<x)][x]=dp[curr][i]+1;
            } 
        }
    }
    pii ans={0x3f3f3f3f,0x3f3f3f3f};
    for (int curr=1;curr<(1<<n);++curr){
        if (dp[curr][end]!=-1) ans=min(ans,{abs(v-dp[curr][end]),dp[curr][end]});
    }
    cout << ans.second << '\n';
    
}