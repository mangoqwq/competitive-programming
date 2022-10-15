#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int dist[301][301];
vector<pii> graph[301];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,m,q; cin >> n >> m >> q;
    for (int i=0,a,b,c;i<m;++i){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
    }
    memset(dist,0x3f,sizeof dist);
    bool visited[301]={0};
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    int distance,node;
    for (int a=1;a<=n;++a){
        memset(visited,0,sizeof visited); pq.push({0,a});
        while (!pq.empty()){
            distance=pq.top().first; node=pq.top().second; pq.pop();
            if (!visited[node]){
                visited[node]=1;
                for (auto&&x:graph[node]){
                    if (dist[a][x.first]>max(x.second,distance)){
                        dist[a][x.first]=max(x.second,distance);
                        pq.push({dist[a][x.first],x.first});
                    }
                }
            }
        }
    }
    for (int i=0,a,b;i<q;++i){
        cin >> a >> b;
        if (dist[a][b]==0x3f3f3f3f) cout << -1 << '\n';
        else cout << dist[a][b] << '\n';
    }
}