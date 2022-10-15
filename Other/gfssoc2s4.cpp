#include <bits/stdc++.h>
#include <queue>

using namespace std;
#define INF 1073741825
vector<pair<int,int>> graph[500001];
vector<pair<int,int>> graph2[500001];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int nodes,edges,a,b,c; cin >> nodes >> edges; 
    for (int i=0;i<edges;++i){cin>>a>>b>>c; graph[a].push_back({b,c}); graph2[b].push_back({a,c});}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; int visited[nodes+1]={0},diststart[nodes+1],distend[nodes+1]; pair<int,int> uwu;
    for(int i=0;i<nodes+1;++i){diststart[i]=INF;distend[i]=INF;} diststart[1]=0; pq.push({0,1}); //weight, node
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
    for(int i=0;i<nodes+1;++i){visited[i]=0;}
    pq.push({0,nodes}); distend[nodes]=0;
    while (!pq.empty()){
        uwu=pq.top();
        pq.pop();
        if (!visited[uwu.second]){
            visited[uwu.second]=1;
            for (auto&&x:graph2[uwu.second]){
                if (!visited[x.first]&&x.second+uwu.first<distend[x.first]){
                    distend[x.first]=x.second+uwu.first;
                    pq.push({distend[x.first],x.first});
                }
            }
        }
    }
    int otherpaths,mininum=distend[1]; cin >> otherpaths;
    for (int i=0;i<otherpaths;++i){
        cin >> a >> b >> c;
        mininum=min(mininum,abs(diststart[a]+c+distend[b]));
    }
    if (mininum==INF){
        cout << -1 << '\n';
    }
    else{
        cout << mininum << '\n';
    }
}