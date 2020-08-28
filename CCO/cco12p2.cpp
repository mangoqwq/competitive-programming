#include <bits/stdc++.h>
#include <queue>

using namespace std;
vector<pair<int,int>> graph[20001]; vector<pair<int,int>> graph2[20001];
int visited[20001],visited2[20001];

int main(){
    int nodes,edges,a,b,c; cin >> nodes >> edges;
    for (int i=0;i<edges;++i){cin >> a >> b >> c; graph[a].push_back({b,c}); graph2[b].push_back({a,c});}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; pair<int,int> uwu;
    int diststart[nodes+1],distend[nodes+1]; 
    memset(diststart,0x3f,sizeof diststart); memset(distend,0x3f,sizeof distend); 
    pq.push({0,1}); diststart[1]=0; //{weight, node}
    while (!pq.empty()){
        uwu=pq.top();
        pq.pop();
        if (!visited[uwu.second]){
            visited[uwu.second]=1;
            for (auto&&x:graph[uwu.second]){
                if (!visited[x.first]&&x.second+uwu.first<diststart[x.first]){
                    diststart[x.first]=x.second+uwu.first;
                    pq.push({diststart[x.first],x.first});
                }
            }
        }
    }
    pq.push({0,nodes}); distend[nodes]=0; //{weight, node}
    while (!pq.empty()){
        uwu=pq.top();
        pq.pop();
        if (!visited2[uwu.second]){
            visited2[uwu.second]=1;
            for (auto&&x:graph2[uwu.second]){
                if (!visited2[x.first]&&x.second+uwu.first<distend[x.first]){
                    distend[x.first]=x.second+uwu.first;
                    pq.push({distend[x.first],x.first});
                }
            }
        }
    }
    int shortestpath=diststart[nodes],ans=0x3f3f3f3f;
    for (int i=1;i<nodes+1;++i){
        for(auto&&x:graph[i]){
            if (diststart[i]+distend[x.first]+x.second<ans && diststart[i]+distend[x.first]+x.second>shortestpath){
                ans=diststart[i]+distend[x.first]+x.second;
            }
        }
    }
    if (ans==0x3f3f3f3f){
        cout << -1 << '\n';
    }
    else{
        cout << ans;
    }
}