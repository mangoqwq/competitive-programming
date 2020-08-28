#include <bits/stdc++.h>
#include <queue>

using namespace std;
#define INF 0x3f3f3f3f;
int visited[1601][3601];
int dist[1601][3601];
typedef pair<pair<int,int>,int> ppp;
vector<ppp> graph[1601];
priority_queue<ppp,vector<ppp>,greater<ppp>> pq;

int main(){
    int health,nodes,edges; cin >> health >> nodes >> edges; 
    for (int i=0;i<edges;++i){
        int a,b,time,above; cin >> a >> b >> time >> above;
        if (above){
            graph[a].push_back({{b,time},time}); graph[b].push_back({{a,time},time});
        }
        else{
            graph[a].push_back({{b,time},0}); graph[b].push_back({{a,time},0});
        }
        
        //{node, time to traverse node, damage to hull}
    }
    
    ppp uwu;
    memset(dist,0x3f,sizeof dist); dist[0][0]=0;
    pq.push({{dist[0][0],0},0}); //{distance[node][damage taken],node,damage taken}

    while (!pq.empty()){
        uwu=pq.top(); pq.pop();
        //cout << uwu.first.first << " " <<[uwu.first.second << " " << uwu.second<< '\n';
        if (!visited[uwu.first.second][uwu.second]){
            visited[uwu.first.second][uwu.second]=1;
            for (auto&&x:graph[uwu.first.second]){
                //cout <<[uwu.first.second << "->" << x.first.first << " " << uwu.second+x.second << " " << uwu.first.first+x.first.second << ":" << dist[x.first.first][uwu.second+x.second] << '\n';
                if (!visited[x.first.first][uwu.second+x.second] && uwu.second+x.second<=health && (uwu.first.first+x.first.second)<dist[x.first.first][uwu.second+x.second]){
                    dist[x.first.first][uwu.second+x.second]=uwu.first.first+x.first.second;
                    pq.push({{dist[x.first.first][uwu.second+x.second],x.first.first},uwu.second+x.second});
                }
            }
        }
    }
    int shortest=INF;
    for (int i=0;i<=health;++i){
        shortest=min(shortest, dist[nodes-1][i]);
    }
    if (shortest==0x3f3f3f3f){
        cout << -1 << '\n';
    }
    else{
        cout << shortest << '\n';
    }
    /*
    for (auto&&x:dist[nodes-1]){
        if (x!=0x3f3f3f3f){
            cout << x << " ";
        }
    }
    */
    
}
