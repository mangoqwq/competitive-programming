#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

ll val[MAXN], in[MAXN], sz[MAXN], tot; int deg[MAXN];
vector<int> adj[MAXN], rev[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> val[i], in[i]=sz[i]=val[i], tot-=val[i];
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
        deg[b]++;
    }
    queue<int> q;
    for (int i=1;i<=n;++i) if (!deg[i]) q.push(i);
    while (!q.empty()){
        int v=q.front(); q.pop();
        tot+=val[v]*in[v];
        for (int to:adj[v]){
            deg[to]--;
            if (deg[to]==0) q.push(to);
            in[to]+=in[v];
        }
    }
    for (int i=1;i<=n;++i){
        deg[i]=adj[i].size();
        if (!deg[i]) q.push(i);
    }
    while (!q.empty()){
        int v=q.front(); q.pop();
        for (int to:rev[v]){
            deg[to]--;
            if (deg[to]==0) q.push(to);
            sz[to]+=sz[v];
        }
    }
    ll best=0;
    for (int i=1;i<=n;++i){
        for (int to:adj[i]){
            best=max(best,(in[to]-in[i])*(sz[i]-sz[to]));
        }
    }
    cout << best+tot << '\n';
}