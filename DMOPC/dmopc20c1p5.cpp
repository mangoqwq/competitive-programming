#include <bits/stdc++.h>

// Subtasks 1 and 2

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1, L=19;

int n, k, m, c[MAXN], ans[MAXN], in[MAXN], out[MAXN], T, up[MAXN][L+1];
vector<int> adj[MAXN];
vector<int> arr[MAXN];
bitset<2001> hehe[2001];
bool subtask1;

void dfs1(int v, int p){
    hehe[v].reset(); hehe[v][c[v]]=1;
    for (int to:adj[v]){
        if (to==p) continue;
        dfs1(to,v);
        hehe[v]|=hehe[to];
    }
    ans[v]=hehe[v].count();
}

void dfs2(int v, int p){
    in[v]=++T;
    up[v][0]=p;
    for (int i=1;i<=L;++i) up[v][i]=up[up[v][i-1]][i-1];
    for (int to:adj[v]){
        if (to==p) continue;
        dfs2(to,v);
    }
    out[v]=T;
}

int dfs3(int v, int p){
    for (int to:adj[v]){
        if (to==p) continue;
        ans[v]+=dfs3(to,v);
    }
    return ans[v];
}

bool is(int a, int b){ return in[a]<=in[b] && out[a]>=out[b]; }

int lca(int a, int b){
    if (is(a,b)) return a;
    if (is(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!is(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}

bool cmp(int a, int b){ return in[a]<in[b]; }

void build(){
    dfs2(1,1);
    for (int i=1;i<=n;++i){
        ans[i]++;
        arr[c[i]].push_back(i);
    }
    for (int i=1;i<=k;++i){
        sort(arr[i].begin(),arr[i].end(),cmp);
        for (int j=1;j<arr[i].size();++j){
            ans[lca(arr[i][j-1],arr[i][j])]--;
        }
    }
    dfs3(1,1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> m;
    if (n<=2000 && m<=2000) subtask1=1;
    for (int i=1;i<=n;++i){
        cin >> c[i];
    }
    for (int i=1,a,b;i<=n-1;++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if (subtask1) dfs1(1,1);
    else build();
    for (int i=1,op,a,b;i<=m;++i){
        cin >> op;
        if (op==1){
            cin >> a >> b;
            c[a]=b;
            dfs1(1,1);
        }
        if (op==2){
            cin >> a;
            cout << ans[a] << '\n';
        }
    }
}