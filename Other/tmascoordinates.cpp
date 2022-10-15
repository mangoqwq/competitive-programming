#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

struct Edge{ int n, w, nxt; } adj[2*MAXN];
struct Item{
    int f, s;
    void ins(int x){
        if (x>f) s=f, f=x;
        else if (x>s) s=x;
    }
    int rem(int x){
        if (x==f) return s;
        return f;
    }
} ecc[MAXN];
int head[MAXN], T, ans[MAXN];

int dfs1(int v, int p){
    for (int i=head[v];i;i=adj[i].nxt){
        int to=adj[i].n, w=adj[i].w;
        if (to==p) continue;
        ecc[v].ins(dfs1(to,v)+w);
    }
    return ecc[v].f;
}

void dfs2(int v, int p, int pre){
    ans[v]=max(ecc[v].f,pre);
    for (int i=head[v];i;i=adj[i].nxt){
        int to=adj[i].n, w=adj[i].w;
        if (to==p) continue;
        dfs2(to,v,max(ecc[v].rem(ecc[to].f+w),pre)+w);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n-1;++i){
        int a, b, c; cin >> a >> b >> c;
        adj[++T]={b,c,head[a]}, head[a]=T;
        adj[++T]={a,c,head[b]}, head[b]=T;
    }
    dfs1(1,1), dfs2(1,1,0);
    while (q--){
        int x; cin >> x;
        cout << ans[x] << '\n';
    }
}