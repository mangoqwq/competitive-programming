#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=998244353;
const int seed=131,MAXN=300'001,L=21;

vector<int> graph[MAXN];
ll p[MAXN][51],pre[51][MAXN];
int up[MAXN][L+1];
int in[MAXN],out[MAXN],t,high;
int dist[MAXN];

void dfs(int node, int prev,int d){
    in[node]=++t;
    dist[node]=d; high=max(high,d);
    up[node][0]=prev;
    for (int l=1;l<=L;++l){
        up[node][l]=up[up[node][l-1]][l-1];
    }
    for (int x:graph[node]){
        if (x==prev) continue;
        dfs(x,node,d+1);
    }
    out[node]=t;
}

bool is_anc(int a, int b){
    return in[a]<=in[b]&&out[a]>=out[b];
}

int lca(int a, int b){
    if (is_anc(a,b)) return a;
    if (is_anc(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!is_anc(up[a][i],b))
            a=up[a][i];
    }
    return up[a][0];
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    
    int n; cin >> n;
    for (int i=0,a,b;i<n-1;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,1,0);
    for (ll i=0;i<high+1;++i){
        p[i][0]=1;
        for (int k=1;k<=50;++k){
            p[i][k]=(p[i][k-1]*i)%mod;
        }
    }
    for (int i=0;i<=50;++i){
        pre[i][0]=0;
        for (int k=1;k<high+1;++k){
            pre[i][k]=(pre[i][k-1]+p[k][i])%mod;
        }
    }
    int q; cin >> q;
    int c;
    for (int i=0,a,b,k;i<q;++i){
        cin >> a >> b >> k;
        c=dist[lca(a,b)];
        a=dist[a]; b=dist[b];
        //cout << a << " " << b << " " << c << '\n';
        cout << (pre[k][a]-(c==0 ? 0:pre[k][c-1])+pre[k][b]-pre[k][c]+3*mod)%mod << '\n';
    }
}