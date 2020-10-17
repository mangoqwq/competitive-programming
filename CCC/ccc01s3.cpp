#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=26;

struct Edge{ int n, idx; };
vector<Edge> adj[MAXN];
pair<char,char> edges[MAXN*MAXN];
bool vis[MAXN];

void dfs(int v, int i){
    vis[v]=1;
    for (Edge x:adj[v]){
        if (vis[x.n]||x.idx==i) continue;
        dfs(x.n,i);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    char a, b;
    int cnt=1;
    while (true){
        cin >> a >> b;
        edges[cnt]={a,b};
        if (a=='*') break;
        a-='A'; b-='A';
        adj[a].push_back({b,cnt});
        adj[b].push_back({a,cnt++});
    }
    int ans=0;
    for (int i=1;i<=cnt;++i){
        ms(vis,0);
        dfs(0,i);
        if (!vis[1]){
            printf("%c%c\n", edges[i].first, edges[i].second);
            ans++;
        }
    }
    printf("There are %d disconnecting roads.\n", ans);
}