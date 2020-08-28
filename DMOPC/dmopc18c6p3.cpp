#include <bits/stdc++.h>

using namespace std;
vector<int> graph[200001]; int visited[200001];

int main(){
    int nodes,edges,a,b; cin >> nodes >> edges;
    for (int i=0;i<edges;++i){
        cin >> a >> b;
        graph[a].push_back(b); graph[b].push_back(a);
    }
    queue<int> q; int uwu,connected=0;
    for (int i=1;i<nodes+1;++i){
        if (!visited[i]){
            connected++;
            q.push(i);
            while (!q.empty()){
                uwu=q.front(); q.pop();
                if (!visited[uwu]){
                    visited[uwu]=1;
                    for (auto&&x:graph[uwu]){
                        q.push(x);
                    }
                }
            }
        }
    }
    if (edges==nodes-connected || edges==nodes-connected+1){
        cout << "YES" << '\n';
    }
    else{
        cout << "NO" << '\n';
    }
}