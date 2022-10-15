#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// LCA

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1,L=17,inf=0x3f3f3f3f;

struct Up{int f,s,p;} up[MAXN][L+1];
struct Edge{int n,w;}; 

int t,in[MAXN],out[MAXN];
vector<Edge> graph[MAXN];

void upd(int &f, int &s, int val){
    if (val>=f) s=f, f=val;
    else if (val>=s) s=val;
}

void dfs(int node, int prev, int dist){
    in[node]=++t;
    up[node][0].p=prev; upd(up[node][0].f,up[node][0].s,dist);
    for (int i=1;i<=L;++i){
        Up temp=up[node][i-1];
        up[node][i].p=up[temp.p][i-1].p;
        upd(up[node][i].f,up[node][i].s,temp.f);
        upd(up[node][i].f,up[node][i].s,temp.s);
        upd(up[node][i].f,up[node][i].s,up[temp.p][i-1].f);
        upd(up[node][i].f,up[node][i].s,up[temp.p][i-1].s);
    }
    for (Edge x:graph[node]){
        if (x.n==prev) continue;
        dfs(x.n,node,x.w);
    }
    out[node]=t;
}

bool is_anc(int a,int b){
    return in[a]<=in[b]&&out[a]>=out[b];
}

int lca(int a, int b){
    if (is_anc(a,b)) return a;
    if (is_anc(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!is_anc(up[a][i].p,b))
            a=up[a][i].p;
    }
    return up[a][0].p;
}

void query(int &f, int &s, int node, int anc){
    if (node==anc) return;
    for (int i=L;i>=0;--i){
        if (!is_anc(up[node][i].p,anc)){
            upd(f,s,up[node][i].f);
            upd(f,s,up[node][i].s);
            node=up[node][i].p;
        }
    }
    upd(f,s,up[node][0].f);
    upd(f,s,up[node][0].s);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    ms(up,-1);
    int n; cin >> n;
    for (int i=1,a,b,c;i<n;++i){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    dfs(1,1,-1);

    int q; cin >> q;
    int c,f,s;
    for (int i=0,a,b;i<q;++i){
        cin >> a >> b;
        f=s=-1;
        c=lca(a,b);
        query(f,s,a,c);
        query(f,s,b,c);
        cout << s << '\n';
    }
}