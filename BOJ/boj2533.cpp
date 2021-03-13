#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int n, dp[MAXN][2];
int nxt[2*MAXN], nd[2*MAXN], h[MAXN], T;

void dfs(int v, int p){
    dp[v][1]=1;
    for (int i=h[v];i;i=nxt[i]){
        int to=nd[i];
        if (to==p) continue;
        dfs(to,v);
        dp[v][0]+=dp[to][1];
        dp[v][1]+=dp[to][0];
    }
    dp[v][0]=min(dp[v][0],dp[v][1]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<n;++i){
        int a, b; cin >> a >> b;
        nd[++T]=b, nxt[T]=h[a], h[a]=T;
        nd[++T]=a, nxt[T]=h[b], h[b]=T;
    }
    dfs(1,1);
    cout << min(dp[1][0],dp[1][1]) << '\n';
}