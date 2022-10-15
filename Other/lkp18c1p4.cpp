#include <bits/stdc++.h>
#include <queue>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
typedef long long ll;

int nodes,edges,start,final; ll mintime; vector<pair<int,pair<int,int>>> graph[100001];
ll dist[100001];
priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

bool dijkstra(int level){
    int visited[100001]={0};pair<ll,int> uwu; pq.push(make_pair(0,start)); //distance,edge
    memset(dist,0x3f,sizeof(dist)); 
    dist[start]=0;
    while (!pq.empty()){
        uwu=pq.top();
        pq.pop();
        if (!visited[uwu.second]){
            visited[uwu.second]=1;
            for (auto&&x:graph[uwu.second]){
                if (x.second.second<=level&&x.second.first+dist[uwu.second]<dist[x.first]){
                    //cout << x[0] << " ";
                    dist[x.first]=x.second.first+dist[uwu.second];
                    pq.push({dist[x.first],x.first});
                }
            }
        }
    }
    //cout << dist[final] << '\n';
    if (dist[final]<mintime){
        return true;
    }
    else{return false;}
}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> nodes >> edges;
    int _,__,___;
    for (int i=1;i<edges+1;++i){cin >> _ >> __ >> ___; graph[_].push_back({__,{___,i}}); graph[__].push_back({_,{___,i}});}
    cin >> start >> final; cin >> mintime;
    int floor=1,ceil=200001; bool end=false;
    for (int i=0;i<18;++i){
        int temp=(ceil+floor)/2;
        //cout << floor << " & " << ceil << '\n';
        if (dijkstra(temp)){
            if (!dijkstra(temp-1)){
                cout << temp << '\n';
                end=true;
                break;
            }
            else{ceil=temp;}
        }
        else{floor=temp;}
    }
    if (start==final){
        cout << 0;
    }
    else if (end==false){
        cout << -1 << '\n';
    }
}