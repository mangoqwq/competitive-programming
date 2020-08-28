#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int cities, roads, destinations;
    cin >> cities >> roads >> destinations;

    vector<pair<int,int>> edges[cities+1];
    vector<pair<int,int>> graph[cities+1];
    priority_queue<vector<int>> pq;

    for (int i=0;i<roads;++i){
        int temp1,temp2,temp3;
        cin >> temp1 >> temp2 >> temp3;
        edges[temp1].push_back(make_pair(temp2,temp3));
        edges[temp2].push_back(make_pair(temp1,temp3));
    }

    int visited[cities+1];
    for (int i=0; i<cities+1;++i){
        visited[i]=0;
    }
    visited[1]=1;
    for (int i=0;i<edges[1].size();++i){
        pq.push({edges[1][i].second,1,edges[1][i].first});
    }
    vector<int> uwu;
    int totaledges=0;
    while ((pq.empty()!=true) || (totaledges == cities-1)){
        uwu=pq.top();
        pq.pop();
        if (!visited[uwu[2]]){ //if not visited
            visited[uwu[2]]=1;
            for (int i=0;i<edges[uwu[2]].size();++i){
                pq.push({edges[uwu[2]][i].second,uwu[2],edges[uwu[2]][i].first});
            }
            graph[uwu[1]].push_back(make_pair(uwu[2],uwu[0]));
            graph[uwu[2]].push_back(make_pair(uwu[1],uwu[0]));
        }
        
    }
    int distance[cities+1];
    for (int i=0; i<cities+1;++i){
        visited[i]=0;
    }
    distance[1]=100000;
    visited[1]=1;
    stack<vector<int>> s;
    for (int i=0;i<graph[1].size();++i){
        s.push({1,graph[1][i].first,graph[1][i].second}); //city 1, city 2, weight
    }
    while (!s.empty()){
        uwu=s.top();
        s.pop();
        distance[uwu[1]]=min(distance[uwu[0]],uwu[2]);
        if (!visited[uwu[1]]){
            for (int i=0;i<graph[uwu[1]].size();++i){
                if (!visited[graph[uwu[1]][i].first]){
                    s.push({uwu[1],graph[uwu[1]][i].first,graph[uwu[1]][i].second}); //city 1, city 2, weight
                }
            }
            visited[uwu[1]]=1;
        }
    }
    int mininum=100000;
    int temp;
    for (int i=0;i<destinations;++i){
        cin >> temp;
        mininum=min(distance[temp],mininum);
    }
    cout<< mininum;

}