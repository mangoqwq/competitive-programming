#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main(){
    int nodes,edges;
    cin >> nodes >> edges;
    vector<pair<int,float>> graph[nodes+1];
    int x,y,dist,speed;
    for (int i=0;i<edges;++i){
        cin >> x >> y >> dist >> speed;
        graph[x].push_back(make_pair(y,dist*60.0/speed));
        graph[y].push_back(make_pair(x,dist*60.0/speed));
    }
    int visited[nodes+1]={0};
    float distance[nodes+1];
    int roads[nodes+1]={0};
    priority_queue<vector<float>,vector<vector<float>>, greater<vector<float>>> pq; // pair <dist,node>
    for (int i=0;i<nodes+1;i++){
        distance[i]=10000001;
    }
    distance[1]=0;
    pq.push({distance[1],0,1});
    vector<float> uwu;
    while (!pq.empty()){
        uwu=pq.top(); pq.pop();
        if (!visited[(int)uwu[2]]){
            for (auto&&edge:graph[(int)uwu[2]]){
                if (!visited[edge.first]){
                    if (uwu[0]+edge.second<distance[edge.first]){
                        distance[edge.first]=uwu[0]+edge.second;
                        roads[edge.first]=uwu[1]+1;
                        pq.push({distance[edge.first],((float)roads[edge.first]),(float)edge.first});
                    }
                }
                
            }
            visited[(int)uwu[2]]=1;
        }
    }
    cout << roads[nodes] << '\n';
    cout << (int)round(distance[nodes]/3) << '\n';


}