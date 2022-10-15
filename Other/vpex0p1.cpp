#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e4+1;

int dist[MAXN],minb[MAXN],maxb[MAXN];
bool vis[MAXN];
struct Edge{int n,w;};
vector<Edge> graph[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,m; cin >> n >> m;
    for (int i=0,a,b,c;i<m;++i){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    queue<int> q; q.push(1);
    ms(minb,0x3f); ms(dist,0x3f);
    dist[1]=0;
    minb[1]=0; maxb[1]=0;
    int cnt=0,curr;
    while (!q.empty()){
        int qsize=q.size();
        for (int i=0;i<qsize;++i){
            curr=q.front(); q.pop();
            for (Edge x:graph[curr]){
                if (dist[x.n]==dist[curr]+1||dist[x.n]==0x3f3f3f3f){
                    minb[x.n]=min(minb[x.n],minb[curr]+x.w);
                    maxb[x.n]=max(maxb[x.n],maxb[curr]+x.w);
                    if (dist[x.n]==0x3f3f3f3f) dist[x.n]=dist[curr]+1, q.push(x.n);
                }
            }
        }
        cnt++;
    }
    int Q; cin >> Q;
    string op;
    for (int i=0,a;i<Q;++i){
        cin >> a >> op;
        cout << dist[a] << " ";
        if (op=="Black") cout << minb[a] << '\n';
        if (op=="White") cout << maxb[a] << '\n';
    }
}