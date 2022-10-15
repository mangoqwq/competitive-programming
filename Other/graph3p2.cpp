#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1001;

struct Edge{int n, w; };
vector<Edge> adj[MAXN];
bool in[MAXN];
int d[MAXN];
queue<int> q;


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1,a,b,c;i<=m;++i){
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    ms(d,0x3f); d[1]=0;
    q.push(1);
    while (!q.empty()){
        int v=q.front(); q.pop(); in[v]=0;
        for (Edge x:adj[v]){
            if (d[v]+x.w < d[x.n]){
                d[x.n]=d[v]+x.w;
                if (!in[x.n]) q.push(x.n);
                in[x.n]=1;
            }
        }
    }
    cout << d[n] << '\n';

}