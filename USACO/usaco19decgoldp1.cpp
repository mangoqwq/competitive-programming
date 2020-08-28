#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
vector<pair<int,pii>> graph[1001];
int dist[1001][1001]; // node, flow (cost)
bool visited[1001][1001];

int main(){
    int nodes, edges; cin >> nodes >> edges;
    for (int i=0,a,b,c,d;i<edges;++i){
        cin >> a >> b >> c >> d;
        graph[a].push_back({b,{c,d}}); //{node,{cost,flow}}
        graph[b].push_back({a,{c,d}});
    }
    priority_queue<piii,vector<piii>,greater<piii>> pq; // {{cost,flow},node}
    memset(dist,0x3f,sizeof dist);
    int cost, flow, node;
    pq.push({{0,1000},1});
    while (!pq.empty()){
        cost=pq.top().f.f; flow=pq.top().f.s; node=pq.top().s; pq.pop();
        if (!visited[node][flow]){
            visited[node][flow]=1;
            for (auto&&x:graph[node]){
                if (dist[x.f][min(x.s.s,flow)]>cost+x.s.f){
                    dist[x.f][min(x.s.s,flow)]=cost+x.s.f;
                    pq.push({{cost+x.s.f,min(x.s.s,flow)},x.f});
                }
            }
        }
    }
    double uwu=-1;
    for (int i=1;i<1001;++i){
        if (visited[nodes][i]){
        uwu=max(uwu,(double)i/(double)dist[nodes][i]);
        }
    }
    cout << (long long) (uwu*1000000) << '\n';
}