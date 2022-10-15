#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=1e6+1;

struct Edge{ int n, nxt; bool b; };
int h1[MAXN], h2[MAXN], i1, i2;
Edge adj[2*MAXN], span[MAXN];
int back[MAXN], n, m, d[MAXN];
double ans;

void dfs1(int curr, int prev){
    d[curr]=d[prev]+1;
    for (int i=h1[curr];i!=0;i=adj[i].nxt){
        Edge x=adj[i];
        if (x.n==prev) continue;
        if (d[x.n]){
            if (d[x.n]<d[curr]) back[curr]++;
            else back[curr]--;
            continue;
        }
        dfs1(x.n,curr);
        span[++i2]={x.n,h2[curr],0}, h2[curr]=i2;
    }
}

int dfs2(int curr){
    int val=0;
    for (int i=h2[curr];i!=0;i=span[i].nxt){
        Edge &x=span[i];
        int temp=dfs2(x.n);
        if (temp==0) x.b=1;
        val+=temp;
    }
    val+=back[curr];
    return val;
}

int dfs3(int curr, bool b){
    int sz=1;
    for (int i=h2[curr];i!=0;i=span[i].nxt){
        Edge x=span[i];
        sz+=dfs3(x.n,x.b);
    }
    if (b) ans+=((double)sz)/n*(sz-1)/(n-1);
    return (b?0:sz);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1,a,b;i<=m;++i){
        cin >> a >> b;
        adj[++i1]={b,h1[a],0}, h1[a]=i1;
        adj[++i1]={a,h1[b],0}, h1[b]=i1;
    }
    dfs1(1,1);
    dfs2(1);
    dfs3(1,1);
    printf("%.5f\n",1-ans);
}