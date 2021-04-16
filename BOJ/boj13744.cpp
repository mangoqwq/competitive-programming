#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e3+1;

int x[MAXN], y[MAXN];
int in[MAXN], low[MAXN], ins[MAXN], T, sccs, ord[MAXN];
stack<int> stk;
vector<int> adj[MAXN];

void dfs(int v){
    in[v]=low[v]=++T;
    stk.push(v); ins[v]=1;
    for (int to:adj[v]){
        if (!in[to]){
            dfs(to);
            low[v]=min(low[v],low[to]);
        }
        else if (ins[to]){
            low[v]=min(low[v],in[to]);
        }
    }
    if (in[v]==low[v]){
        sccs++;
        while (true){
            int to=stk.top(); stk.pop();
            ord[to]=sccs; ins[to]=0;
            if (to==v) break;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, d, m; cin >> n >> d >> m;
    for (int i=1;i<=m;++i) cin >> x[i] >> y[i];
    for (int i=1;i<=m;++i){
        for (int j=1;j<=m;++j){
            if (i==j) continue;
            if (y[i]==y[j]&&abs(x[i]-x[j])<=2*d){
                adj[i].push_back(j+m);
            }
            if (x[i]==x[j]&&abs(y[i]-y[j])<=2*d){
                adj[i+m].push_back(j);
            }
        }
    }
    for (int i=1;i<=2*m;++i) if (!in[i]) dfs(i);
    bool ans=1;
    for (int i=1;i<=m;++i){
        ans&=ord[i]!=ord[i+m];
    }
    cout << ans << '\n';
}