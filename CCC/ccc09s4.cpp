#include<bits/stdc++.h>
#include <queue>
using namespace std;

const int inf=0x3f3f3f3f;
int dist[5001];
vector<pair<int,int>> graph[5001];
int cost[5001];

int main(){
    //cin.sync_with_stdio(0);
    //cin.tie(0);
    memset(dist, inf,sizeof dist);
    memset(cost,-1,sizeof cost);
    //initalizing stuff thing
    int nodes, edges,a,b,c;
    cin >> nodes >> edges;
    for (int i=0;i<edges;++i){
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    int stores;
    cin >>  stores;
    for (int i=0;i<stores;++i){
        cin >> a >> b;
        cost[a]=b;
    }
    int src;
    cin >> src;
    //dijkstra's
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for (int i=1;i<nodes+1;++i){
        pq.push(make_pair(dist[i],i));
    }
    pair<int,int> uwu; int visited[5001]={0},temp;
    while (!pq.empty()){
        uwu=pq.top();
        pq.pop();
        if (!visited[uwu.second]){
            for (auto&&x:graph[uwu.second]){
                temp=x.second+dist[uwu.second];
                if (temp<dist[x.first]){
                    dist[x.first]=temp;
                    pq.push(make_pair(temp,x.first));
                }
            }
        }
        visited[uwu.second]=1;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i=0;i<5001;++i){
        if (cost[i]>-1){
            q.push(dist[i]+cost[i]);
        }
    }
    cout << q.top() << '\n';
}