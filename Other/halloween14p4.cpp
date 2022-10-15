#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const ll mod=1e9+7, MAXN=1e5+1;
const ll inf=0x3f3f3f3f3f3f3f3f;

vector<int> adj[MAXN];
bool onloop[MAXN]; vector<int> loop;
int dep[MAXN], par[MAXN];
ll t[MAXN], dp[MAXN][3], rdp[MAXN][3];
ll finalans=0;

void findloop(int v){
    bool backed=0;
    for (int to:adj[v]){
        if (to==par[v]&&!backed){
            backed=1; continue;
        }
        if (!dep[to]){
            dep[to]=dep[v]+1;
            par[to]=v;
            findloop(to);
        }
        if (dep[to]<dep[v]){
            for (int i=v;;i=par[i]){
                loop.push_back(i);
                onloop[i]=1;
                if (i==to) break;
            }
        }
    }
}

void dfs(int v, int p){
    dp[v][0]=t[v];
    ll mn=inf, tot=0;
    dp[v][2]=0;
    for (int to:adj[v]){
        if (to==p||onloop[to]) continue;
        dfs(to,v);
        dp[v][0]+=dp[to][2];
        mn=min(mn,dp[to][0]-dp[to][1]);
        tot+=dp[to][1];
        dp[v][2]+=dp[to][1];
    }
    dp[v][1]=tot+mn;
    dp[v][1]=min(dp[v][1],dp[v][0]);
    dp[v][2]=min(dp[v][2],dp[v][1]);
}

void work(){
    for (int _=1;_<loop.size();++_){
        int v=loop[_], p=loop[_-1];
        rdp[v][0]=rdp[p][2]+dp[v][0];
        rdp[v][1]=min(rdp[p][0]+dp[v][2],rdp[p][1]+dp[v][1]);
        rdp[v][2]=rdp[p][1]+dp[v][2];
        rdp[v][1]=min(rdp[v][1],rdp[v][0]);
        rdp[v][2]=min(rdp[v][2],rdp[v][1]);
    }
}

void solve(int src){
    loop.clear();
    dep[src]=1;
    findloop(src);
    for (int x:loop) dfs(x,x);

    int v=loop[0], e=loop.back();

    for (int x:loop) ms(rdp[x],0x3f);
    for (int i=0;i<=2;++i) rdp[v][i]=dp[v][i];
    work();
    ll ans1=rdp[e][1];

    for (int x:loop) ms(rdp[x],0x3f);
    for (int i=0;i<=2;++i) rdp[v][i]=dp[v][0];
    work();
    ll ans2=rdp[e][2];

    for (int x:loop) ms(rdp[x],0x3f);
    rdp[v][0]=dp[v][0];
    rdp[v][1]=rdp[v][2]=dp[v][2];
    work();
    ll ans3=rdp[e][0];
    
    finalans+=min({ans1,ans2,ans3});
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> t[i];
    for (int i=1;i<=n;++i){
        int a; cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    for (int i=1;i<=n;++i) if (!dep[i]) solve(i);
    cout << finalans << '\n';
}