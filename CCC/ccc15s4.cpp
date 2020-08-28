#include <iostream>
#include <queue>

using namespace std;
#define INF 0x3f3f3f3f;
int visited[2001][201];
int dist[2001][201];

int main(){
    int health,nodes,edges; cin >> health >> nodes >> edges; vector<vector<int>> graph[nodes+1];
    for (int i=0;i<edges;++i){
        int a,b,time,damage; cin >> a >> b >> time >> damage;
        graph[a].push_back({b,time,damage}); graph[b].push_back({a,time,damage});\
        //{node, time to traverse node, damage to hull}
    }
    int a,b; cin >> a >> b; priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    vector<int> uwu;
    for (int i=0;i<2001;++i){for (int k=0;k<201;++k){dist[i][k]=INF;}} dist[a][0]=0;
    pq.push({dist[a][0],a,0}); //{distance[node][damage taken],node,damage taken}

    while (!pq.empty()){
        uwu=pq.top(); pq.pop();
        //cout << uwu[0] << " " << uwu[1] << " " << uwu[2]<< '\n';
        if (!visited[uwu[1]][uwu[2]]){
            visited[uwu[1]][uwu[2]]=1;
            for (auto&&x:graph[uwu[1]]){
                //cout << uwu[1] << "->" << x[0] << " " << uwu[2]+x[2] << " " << uwu[0]+x[1] << ":" << dist[x[0]][uwu[2]+x[2]] << '\n';
                if (!visited[x[0]][uwu[2]+x[2]] && uwu[2]+x[2]<health && (uwu[0]+x[1])<dist[x[0]][uwu[2]+x[2]]){
                    dist[x[0]][uwu[2]+x[2]]=uwu[0]+x[1];
                    pq.push({dist[x[0]][uwu[2]+x[2]],x[0],uwu[2]+x[2]});
                }
            }
        }
    }
    int shortest=INF;
    for (int i=0;i<health;++i){
        shortest=min(shortest, dist[b][i]);
    }
    if (shortest==0x3f3f3f3f){
        cout << -1 << '\n';
    }
    else{
        cout << shortest << '\n';
    }
    /*
    for (auto&&x:dist[b]){
        if (x!=0x3f3f3f3f){
            cout << x << " ";
        }
        
    }
    */
}