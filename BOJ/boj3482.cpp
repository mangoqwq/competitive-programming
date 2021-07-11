#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define id(i,j) ((i-1)*m+(j-1))
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1001;

int n, m;
bool g[MAXN*MAXN];
vector<int> adj[MAXN*MAXN];

void dfs(int v, int p, int d, int &far, int &dist){
    if (d>dist) far=v, dist=d;
    for (int to:adj[v]){
        if (to==p) continue;
        dfs(to,v,d+1,far,dist);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> n >> m; swap(n,m);
        int src=-1;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                adj[id(i,j)].clear();
                char a; cin >> a;
                g[id(i,j)]=a=='.';
                if (a=='.'){
                    if (g[id(i-1,j)]){
                        adj[id(i,j)].push_back(id(i-1,j));
                        adj[id(i-1,j)].push_back(id(i,j));
                    }
                    if (g[id(i,j-1)]){
                        adj[id(i,j)].push_back(id(i,j-1));
                        adj[id(i,j-1)].push_back(id(i,j));
                    }
                    src=id(i,j);
                }
            }
        }
        int far, dist;
        if (src==-1) dist=0;
        else{
            dist=-1, dfs(src,src,0,far,dist);
            dist=-1, dfs(far,far,0,far,dist);
        }
        cout << "Maximum rope length is " << dist << '.' << '\n';
    }   
}