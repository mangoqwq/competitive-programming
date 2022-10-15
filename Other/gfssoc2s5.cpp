#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=5e5+1;

int n, m, arr[MAXN], scc[MAXN], val[MAXN];
vector<int> adj[MAXN], adjr[MAXN], graph[MAXN];
set<int> no[MAXN];
bitset<MAXN> vis;
int order[MAXN], T;
struct Item{
    int v, cnt;
    void operator+=(const Item &x){
        if (x.v>v) v=x.v, cnt=x.cnt;
        else if (x.v==v) cnt=(cnt+x.cnt)%mod;
    }
    Item operator+(const Item &x){
        if (x.v>v) return x;
        else if (x.v==v) return {v,(cnt+x.cnt)%mod};
        else return {v,cnt};
    }
    Item operator+(const int &x){
        return {v+x,cnt};
    }
} dp[MAXN][2];

void dfs1(int curr){
    vis[curr]=1;
    for (int x:adj[curr]){
        if (!vis[x]) dfs1(x);
    }
    order[++T]=curr;
}

void dfs2(int curr){
    scc[curr]=T; val[T]+=arr[curr];
    for (int x:adjr[curr]){
        if (!scc[x]) dfs2(x);
        if (scc[x]!=T&&!no[T].count(scc[x])){
            //cout << T << " -> " << scc[x] << '\n';
            no[scc[x]].insert(T);
            graph[scc[x]].push_back(T);
        }
    }
}

void solve(int curr){
    //if (dp[curr][1].cnt==0) return;
    vis[curr]=1;
    for (int x:graph[curr]){
        dp[x][0]+=dp[curr][1];
        dp[x][1]+=dp[curr][0]+val[x];
        dp[x][1]+=dp[curr][1];
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1,a,b;i<=m;++i){
        cin >> a >> b;
        if (a!=b&&!no[a].count(b)) adj[a].push_back(b), adjr[b].push_back(a);
        no[a].insert(b);
    }
    for (int i=1;i<=n;++i){
        if (!vis[i]) dfs1(i);
        no[i].clear();
    }
    T=0;
    for (int i=n;i>=1;--i) if (!scc[order[i]]) T++, dfs2(order[i]);
    vis.reset();
    ms(dp,-0x3f);
    dp[scc[1]][0]={0,1}, dp[scc[1]][1]={val[scc[1]],1};
    for (int curr=1;curr<=T;++curr){
        if (!vis[curr]) solve(curr);
    }
    cout << dp[scc[n]][1].v << " " << dp[scc[n]][1].cnt << '\n';
}