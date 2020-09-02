#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=1e5+1,L=17;

vector<int> graph[MAXN], span[MAXN], back[MAXN];
int depth[MAXN], best[MAXN];
int up[MAXN][L+1], in[MAXN], out[MAXN], T;
bool can[MAXN];
struct Edge{
    int a,b;
    bool operator<(const Edge &x) const{
        return make_pair(a,b)<make_pair(x.a,x.b);
    }
}; set<Edge> bridges;

void build(int curr, int prev){
    in[curr]=++T;
    depth[curr]=depth[prev]+1;
    up[curr][0]=prev;
    for (int i=1;i<=L;++i) up[curr][i]=up[up[curr][i-1]][i-1];
    for (int x:graph[curr]){
        if (x==prev) continue;
        if (depth[x]){
            back[x].push_back(curr);
            back[curr].push_back(x);
            continue;
        }
        build(x,curr);
        span[curr].push_back(x);
        span[x].push_back(curr);
    }
    out[curr]=T;
}

bool Is(int a, int b){ return in[a]<=in[b] && out[a]>=out[b]; }

int Lca(int a, int b){
    if (Is(a,b)) return a;
    if (Is(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!Is(up[a][i],b)) a=up[a][i];
    }
    return up[a][0]; 
}

int Query(int a, int anc){
    for (int i=L;i>=0;--i){
        if (!Is(up[a][i],anc)) a=up[a][i];
    }
    return a;
}

int dfs(int curr, int prev){
    int cnt=0;
    best[curr]=depth[prev];
    for (int x:span[curr]){
        if (x==prev) continue;
        cnt+=dfs(x,curr);
        best[curr]=min(best[curr],best[x]);
    }
    for (int x:back[curr]){
        if (depth[x]>depth[curr]) cnt++;
        if (depth[x]<depth[curr]) cnt--;
        best[curr]=min(best[curr],depth[x]);
    }
    if (cnt==0) bridges.insert({prev,curr});
    can[curr]=best[curr]<depth[prev];
    return cnt;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1,a,b;i<=m;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i=1;i<=n;++i) if (!depth[i]) build(i,i), dfs(i,i);
    int q; cin >> q;
    for (int i=1,cmd,a,b,c,d,lca,ans;i<=q;++i){
        cin >> cmd;
        if (cmd==1){
            cin >> a >> b >> c >> d;
            if (depth[d]<depth[c]) swap(c,d);
            lca=Lca(a,b);
            if (!bridges.count({c,d})) ans=1;
            else if (Is(d,lca)) ans=1;
            else if (Is(c,a)&&Is(d,a)) ans=0;
            else if (Is(c,b)&&Is(d,b)) ans=0;
            else ans=1;
        }
        if (cmd==2){
            cin >> a >> b >> c;
            lca=Lca(a,b);
            int ac=Query(a,c), bc=Query(b,c);
            if (lca==c) ans=can[ac]&&can[bc];
            else if (Is(c,lca)) ans=1;
            else if (Is(c,a)) ans=can[ac];
            else if (Is(c,b)) ans=can[bc];
            else ans=1;
        }
        cout << (ans?"yes":"no") << '\n';
    }
}