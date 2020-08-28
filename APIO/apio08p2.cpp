#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e4+1,MAXM=1e5+1;

struct Edge{
    int a,b,c,id;
    bool operator<(Edge x) const{
        return c<x.c;
    }
} edges[MAXM];
struct Edge2{ int n,c,id; };
vector<Edge2> graph[MAXN];
int deg[MAXN],p[MAXN],sz[MAXN];
bool use[MAXM];

int Find(int a){ return (p[a]==a?a:p[a]=Find(p[a])); }

void Union(int a, int b){
    a=Find(a), b=Find(b);
    if (sz[b]>sz[a]) swap(a,b);
    p[b]=a;
    sz[a]+=sz[b];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    fill(sz,sz+MAXN,1); iota(p,p+MAXN,0);
    int n,m,k; cin >> n >> m >> k;
    for (int i=1,a,b,c;i<=m;++i){
        cin >> a >> b >> c;
        edges[i]={a,b,c,i};
        graph[a].push_back({b,c,i});
        graph[b].push_back({a,c,i});
        deg[a]+=c*2-1;
        deg[b]+=c*2-1;
    }
    for (int i=1;i<=n;++i){
        if (abs(deg[i])==graph[i].size()){
            int idx=0;
            while (Find(i)==Find(graph[i][idx].n)) idx++;
            if (idx>=graph[i].size()) continue;
            Union(i,graph[i][idx].n);
            if (graph[i][idx].c==0) k--;
            use[graph[i][idx].id]=1;
        }
    }
    sort(edges+1,edges+1+m);
    for (int i=1;i<=m;++i){
        Edge &x=edges[i];
        if (x.c==0&&k<=0) continue;
        if (Find(x.a)!=Find(x.b)){
            Union(x.a,x.b);
            use[x.id]=1;
            if (x.c==0) k--;
        }
    }
    if (k!=0||sz[Find(1)]!=n) cout << "no solution" << '\n';
    else{
        for (int i=1;i<=m;++i){
            if (use[edges[i].id]){
                cout << edges[i].a << " " << edges[i].b << " " << edges[i].c << '\n';
            }
        }
    }


}