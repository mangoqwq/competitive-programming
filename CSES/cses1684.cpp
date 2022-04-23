#include <bits/stdc++.h>

// Giant Pizza
// 2-SAT with tarjan's

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int n, m, in[MAXN], low[MAXN], ins[MAXN], T, sccs, ord[MAXN];
stack<int> stk;
bool ans[MAXN];
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
    cin >> n >> m;
    for (int i=1;i<=n;++i){
        char sa, sb; int a, b; 
        cin >> sa >> a >> sb >> b;
        bool ba=sa=='+', bb=sb=='+';
        adj[(ba?a:a+m)].push_back((bb?b+m:b));
        adj[(bb?b:b+m)].push_back((ba?a+m:a));
    }
    for (int i=1;i<=2*m;++i) if (!in[i]) dfs(i);
    bool can=1;
    for (int i=1;i<=m;++i){
        if (ord[i]==ord[i+m]) can=0;
        if (ord[i]<ord[i+m]) ans[i]=0;
        else ans[i]=1;
    }
    if (!can) return cout << "IMPOSSIBLE" << '\n', 0;
    for (int i=1;i<=m;++i){
        cout << (ans[i]?'+':'-') << " ";
    }
    cout << '\n';
}