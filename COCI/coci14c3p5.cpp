#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// LCA

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=300'001,L=19;

struct Query{char op; int a,b;};
vector<Query> queries;

vector<int> graph[MAXN];
int p[MAXN],sz[MAXN],parent[MAXN];
int up[MAXN][L+1],in[MAXN],out[MAXN],T;

void dfs(int node, int prev){
    in[node]=++T;
    up[node][0]=prev;
    for (int i=1;i<=L;++i) up[node][i]=up[up[node][i-1]][i-1];
    for (int x:graph[node]){
        if (x==prev) continue;
        dfs(x,node);
    }
    out[node]=T;
}

int is_anc(int a,int b){
    return in[a]<=in[b]&&out[a]>=out[b];
}

int lca(int a,int b){
    if (is_anc(a,b)) return a;
    if (is_anc(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!is_anc(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<=n;++i) p[i]=i;
    char a; int v,w; 
    for (int i=1;i<=n;++i){
        cin >> a;
        if (a=='a'){
            cin >> v; v=p[v];
            graph[v].push_back(i);
            graph[i].push_back(v);
            sz[i]=sz[v]+1;
            parent[i]=v;
        }
        if (a=='b'){
            cin >> v; v=p[v];
            p[i]=parent[v];
            queries.push_back({'b',v,v});
        }
        if (a=='c'){
            cin >> v >> w; v=p[v],w=p[w];
            p[i]=v;
            queries.push_back({'c',v,w});
        }
    }
    dfs(0,0);
    for (Query x:queries){
        if (x.op=='b'){
            cout << x.b << '\n';
        }
        if (x.op=='c'){
            cout << sz[lca(x.a,x.b)] << '\n';
        }
        
    }
}