//A Noisy Class
#include <bits/stdc++.h>
#include <set>

using namespace std;

vector<int> graph[10001];
int visited[10001];
set<int> s;
bool cycle=false;

void bfs(int node){
    if (!visited[node]){
        visited[node]=1;
        s.insert(node);
        for (auto&&x:graph[node]){
            if (s.find(x)!=s.end()){
                cycle=true;
            }
            if (!visited[x]){
                bfs(x);
            }
        }
        s.erase(node);
    }

}

int main(){
    int nodes,edges,a,b;
    cin >> nodes >> edges;
    for (int i=0;i<edges;++i){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i=1;i<nodes+1;++i){
        bfs(i);
    }
    if (cycle){
        cout << "N" << '\n';
    }
    else{
        cout << "Y" << '\n';
    }


}