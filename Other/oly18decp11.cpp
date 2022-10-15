#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int dist[201][20001],otherdist[201][20001]; vector<pair<int,int>> graph[20001],opposite[20001]; int hub[20001]; map<int,int> key;

int main(){
    int nodes, edges, hubs, queries, a,b,c; scan(nodes); scan(edges); scan(hubs); scan(queries);
    for (int i=0;i<edges;++i){scan(a);scan(b);scan(c); graph[a].push_back({b,c}); opposite[b].push_back({a,c});}
    for (int i=0;i<hubs;++i){scan(a); hub[a]=1;}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; /*{dist,node}*/ int visited[20001]; pair<int,int> uwu; int index=0;
    for (int i=0;i<201;++i){for (int k=0;k<20001;++k){dist[i][k]=0x3f3f3f3f;otherdist[i][k]=0x3f3f3f3f;}}
    for (int k=1;k<nodes+1;++k){
        if (!hub[k]){continue;} else{key.insert({k,index}); index++;}
        memset(visited,0,sizeof visited);
        pq.push({0,k}); dist[key[k]][k]=0;
        while (!pq.empty()){
            uwu=pq.top(); pq.pop();
            if (!visited[uwu.second]){
                visited[uwu.second]=1;
                for (auto&&x:graph[uwu.second]){
                    if (x.second+uwu.first<dist[key[k]][x.first]){
                        dist[key[k]][x.first]=x.second+uwu.first;
                        pq.push({dist[key[k]][x.first],x.first});
                    }
                }
            }
            
        }
    }
    for (int k=1;k<nodes+1;++k){
        if (!hub[k]){continue;}
        memset(visited,0,sizeof visited);
        pq.push({0,k}); otherdist[key[k]][k]=0;
        while (!pq.empty()){
            uwu=pq.top(); pq.pop();
            if (!visited[uwu.second]){
                visited[uwu.second]=1;
                for (auto&&x:opposite[uwu.second]){
                    if (x.second+uwu.first<otherdist[key[k]][x.first]){
                        otherdist[key[k]][x.first]=x.second+uwu.first;
                        pq.push({otherdist[key[k]][x.first],x.first});
                    }
                }
            }
            
        }
    }
    /*
    for (int i=0;i<5;++i){cout << '\n'; for(int k=0;k<5;++k){cout<<dist[i][k] << " ";}}
    for (int i=0;i<5;++i){cout << '\n'; for(int k=0;k<5;++k){cout<<otherdist[i][k] << " ";}}

    cout << "AAA" << queries;
    */
    long long ans=0; int fulfilled=0,mininum=0x3f3f3f3f;
    for (int __=0;__<queries;++__){
        mininum=0x3f3f3f3f;
        scan(a);scan(b);
        for (int k=0;k<hubs;++k){
            mininum=min(mininum,dist[k][b]+otherdist[k][a]);
        }

        if (mininum<200000001){
            fulfilled++;
            ans+=mininum;
        }
        //cout << q.top();

    }
    cout << fulfilled << '\n' << ans << '\n';
    

}