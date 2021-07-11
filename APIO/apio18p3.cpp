#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int n, m, dummy;
vector<int> graph[MAXN], bcc[2*MAXN];
stack<int> stk;
int in[MAXN], link[MAXN];
int val[2*MAXN], sz[2*MAXN];

void tarjan(int v){
    stk.push(v);
    link[v]=in[v];
    for (int to:graph[v]){
        if (!in[to]){
            in[to]=in[v]+1;
            tarjan(to); link[v]=min(link[v],link[to]);
            if (link[to]==in[v]){
                dummy++; stk.push(v); // make link to v
                while (true){
                    val[dummy]++;
                    int u=stk.top(); stk.pop();
                    bcc[dummy].push_back(u);
                    bcc[u].push_back(dummy);
                    if (u==to) break;
                }
            }
        }
        else link[v]=min(link[v],in[to]);
    }
}

ll dfs(int v, int p, ll &ans){
    ll tot=0;
    if (v<=n){
        sz[v]=1;
        tot=val[v];
    }
    for (int to:bcc[v]){
        if (to==p) continue;
        ll add=dfs(to,v,ans);
        ans+=tot*sz[to];
        ans+=add*sz[v];
        sz[v]+=sz[to];
        tot+=add+sz[to]*val[v];
    }
    return tot;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m; dummy=n;
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i=1;i<=n;++i){
        val[i]=-1;
        if (!in[i]) in[i]=1, tarjan(i);
    }
    ll ans=0;
    for (int i=1;i<=n;++i){
        if (in[i]!=1) continue;
        dfs(i,i,ans);
    }
    cout << ans*2 << '\n';
}