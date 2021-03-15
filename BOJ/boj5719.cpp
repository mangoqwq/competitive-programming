#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=501;

int n, m;
struct Edge{ int to, w; };
vector<Edge> sadj[MAXN], radj[MAXN], nadj[MAXN];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int sdist[MAXN], rdist[MAXN], ndist[MAXN];

void dijkstra(int src, int dist[], vector<Edge> adj[]){
    dist[src]=0;
    pq.push({0,src});
    while (!pq.empty()){
        auto [d,v]=pq.top(); pq.pop();
        for (auto [to,w]:adj[v]){
            if (d+w<dist[to]){
                dist[to]=d+w;
                pq.push({dist[to],to});
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    while (true){
        cin >> n >> m;
        if (!n&&!m) break;
        for (int i=0;i<n;++i){
            sadj[i].clear(), radj[i].clear(), nadj[i].clear();
            sdist[i]=rdist[i]=ndist[i]=inf;
        }
        int s, d; cin >> s >> d;
        for (int i=1;i<=m;++i){
            int a, b, c; cin >> a >> b >> c;
            sadj[a].push_back({b,c});
            radj[b].push_back({a,c});
        }
        dijkstra(s,sdist,sadj);
        dijkstra(d,rdist,radj);
        for (int i=0;i<n;++i){
            for (Edge x:sadj[i]){
                if (sdist[i]+rdist[x.to]+x.w==sdist[d]) continue;
                nadj[i].push_back(x);
            }
        }
        dijkstra(s,ndist,nadj);
        cout << (ndist[d]==inf?-1:ndist[d]) << '\n';
    }
}