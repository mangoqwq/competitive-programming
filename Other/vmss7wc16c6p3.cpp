#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

vector<int> adj[MAXN];
int in[MAXN], low[MAXN], T;
bool cut[MAXN];

void dfs(int v, int p=-1){
    in[v]=low[v]=++T;
    int child=0;
    for (int to:adj[v]){
        if (to==p) continue;
        if (in[to]) low[v]=min(low[v],in[to]); 
        else{
            dfs(to,v), low[v]=min(low[v],low[to]);
            child++;
            if (low[to]>=in[v]&&p!=-1) cut[v]=1;
        }
    }
    if (child>=2&&p==-1) cut[v]=1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    cout << accumulate(cut+1,cut+1+n,0) << '\n';
    for (int i=1;i<=n;++i) if (cut[i]) cout << i << '\n';
}