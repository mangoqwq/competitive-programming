#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

unordered_map<char,int> mp={{'r',0},{'o',1},{'y',2},{'g',3},{'b',4},{'i',5},{'v',6}};
struct Edge{ int to; char c; };
vector<Edge> adj[MAXN];
vector<Edge> radj[MAXN];
int deg[MAXN];
queue<int> q;
bool dp[MAXN][1<<7];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int all=0;
    for (int i=1;i<=m;++i){
        int a, b; char c; cin >> a >> b >> c;
        all|=(1<<mp[c]);
        adj[a].push_back({b,c});
        radj[b].push_back({a,c});
    }
    for (int i=1;i<=n;++i){
        deg[i]=adj[i].size();
        if (deg[i]==0) q.push(i);
    }
    while (!q.empty()){
        int v=q.front(); q.pop();
        for (int msk=0;msk<(1<<7);++msk){
            for (auto [to,col]:adj[v]){
                int c=mp[col];
                dp[v][msk]|=!(dp[to][msk|(1<<c)]);
            }
        }
        dp[v][all]=0;
        for (auto [to,c]:radj[v]){
            deg[to]--;
            if (deg[to]==0) q.push(to);
        }
    }
    cout << (dp[1][0]?"piddddgy":"deruikong") << '\n';
}