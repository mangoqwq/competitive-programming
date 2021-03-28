#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e5+1;

int in[MAXN], out[MAXN], T, up[MAXN][21];
vector<int> adj[MAXN];

void dfs(int v, int p){
    in[v]=++T;
    up[v][0]=p;
    for (int i=1;i<=20;++i) up[v][i]=up[up[v][i-1]][i-1];
    for (int to:adj[v]){
        if (to==p) continue;
        dfs(to,v);
    }
    out[v]=T;
}

bool is_anc(int a, int b){ return in[a]<=in[b]&&out[a]>=out[b]; }
int getlca(int a, int b){
    if (is_anc(a,b)) return a;
    if (is_anc(b,a)) return b;
    for (int i=20;i>=0;--i){
        if (!is_anc(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<n;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,1);
    int q; cin >> q;
    while (q--){
        int rt, a, b; cin >> rt >> a >> b;
        cout << (getlca(rt,a)^getlca(rt,b)^getlca(a,b)) << '\n';
    }
}