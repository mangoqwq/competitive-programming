#include <bits/stdc++.h>

using namespace std;
pair<int,int> coords[100001]; int visited[100001]={0}; vector<int> graph[100001];

int main(){
    int nodes,edges,a,b; cin >> nodes >> edges;
    for (int i=1;i<nodes+1;++i){cin>>a>>b;coords[i]={a,b};}
    for (int i=0;i<edges;++i){cin>>a>>b;graph[a].push_back(b);graph[b].push_back(a);}
    priority_queue<int,vector<int>,greater<int>> pq; queue<int> q; 
    for (int i=1;i<nodes+1;++i){
        int uwu,x=0,y=0,minx=100000001,miny=100000001;
        if (!visited[i]){
            visited[i]=1; q.push(i);
            x=max(x,coords[i].first); y=max(y,coords[i].second);
            minx=min(minx,coords[i].first);miny=min(miny,coords[i].second);
            while (!q.empty()){
                uwu=q.front();q.pop();
                for (int node:graph[uwu]){
                    if (!visited[node]){
                        q.push(node); visited[node]=1;
                        x=max(x,coords[node].first); y=max(y,coords[node].second);
                        minx=min(minx,coords[node].first);miny=min(miny,coords[node].second);
                    }
                }
            }
            pq.push((x+y-minx-miny)*2);
        }
    }
    cout << pq.top() << '\n';

}