#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=401;

set<int> adj[MAXN], art;
int in[MAXN], low[MAXN], T, sz;
bool cut[MAXN], vis[MAXN];
ll cnt, ans;

void dfs(int curr, int prev=-1){
    if (adj[curr].empty()) return;
    in[curr]=low[curr]=++T;
    int c=0;
    for (int x:adj[curr]){
        if (x==prev) continue;
        if (in[x]) low[curr]=min(low[curr],in[x]);
        else{
            c++;
            dfs(x,curr);
            low[curr]=min(low[curr],low[x]);
            if (low[x]>=in[curr]&&prev!=-1) cut[curr]=1;
        }
    }
    if (prev==-1&&c>1) cut[curr]=1;
}

void dfs1(int curr){
    sz++; vis[curr]=1;
    for (int x:adj[curr]){
        if (vis[x]) continue;
        if (cut[x]) art.insert(x);
        else dfs1(x);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    while (true){
        int n; cin >> n;
        if (n==0) break;
        for (int i=1;i<MAXN;++i) adj[i].clear();
        ms(in,0); ms(low,0); ms(cut,0); ms(vis,0);
        T=cnt=0; ans=1;
        int m=0;
        for (int i=1,a,b;i<=n;++i){
            cin >> a >> b;
            m=max({m,a,b});
            adj[a].insert(b);
            adj[b].insert(a);
        }
        for (int i=1;i<=m;++i) if (!in[i]) dfs(i);
        for (int i=1;i<=m;++i){
            if (vis[i]||cut[i]||!in[i]) continue;
            sz=0, art.clear();
            dfs1(i);
            if (art.size()==1) cnt++, ans*=sz;
            if (art.size()==0) cnt+=2, ans*=(sz*(sz-1))/2; 
        }
        cout << cnt << " " << ans << '\n';
    }
}