#include <bits/stdc++.h>

using namespace std;
vector<int> gifts;
vector<int> graph[100001];
bool visited[100001];
int diststart[100001];
int distend[100001];

int main(){
    int nodes, edges, stores, start, end;
    cin >> nodes >> edges >> stores >> start >> end;
    for (int i=0,a;i<stores;++i){
        cin >> a;
        gifts.push_back(a);
    }
    for (int i=0,a,b;i<edges;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int> q; q.push(start); int count=0, uwu, qsize;
    while (!q.empty()){
        qsize=q.size();
        for (int i=0;i<qsize;++i){
            uwu=q.front(); q.pop();
            if (!visited[uwu]){
                diststart[uwu]=count;
                visited[uwu]=1;
                for (auto&&x:graph[uwu]){
                    q.push(x);
                }
            }
        }
        count++;
    }
    q.push(end); count=0; memset(visited,0,sizeof visited);
    while (!q.empty()){
        qsize=q.size();
        for (int i=0;i<qsize;++i){
            uwu=q.front(); q.pop();
            if (!visited[uwu]){
                distend[uwu]=count;
                visited[uwu]=1;
                for (auto&&x:graph[uwu]){
                    q.push(x);
                }
            }
        }
        count++;
    }
    int mininum=0x3f3f3f3f;
    for (auto&&x:gifts){
        mininum=min(mininum,diststart[x]+distend[x]);
    }
    cout << mininum << '\n';
}