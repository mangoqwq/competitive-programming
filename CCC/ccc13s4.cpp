#include <iostream>
#include <queue>

using namespace std;


int main(){
    int people,comparisons; 
    cin >> people >> comparisons;
    vector<int> graph[people+1];
    
    int x,y;
    for (int i=0;i<comparisons;++i){
        cin>>x>>y;
        graph[x].push_back(y); //x is taller than y
    }

    int p,q,uwu; //output whether or not p > q , uwu is temp variable
    cin >> p >> q;
    queue<int> bfs;
    int visited[people+1];
    for (int i=0;i<people+1;++i){
        visited[i]=0;
    }
    bfs.push(p);
    while (!bfs.empty()){
        uwu=bfs.front();
        bfs.pop();
        if (visited[uwu]==0){
            for (int i=0;i<graph[uwu].size();++i){
                bfs.push(graph[uwu][i]);
            }
            visited[uwu]=1;
        }
    }
    if (visited[q]==1){
        cout << "yes";
    }
    else{
        queue<int> bfs;
        int visited[people+1];
        for (int i=0;i<people+1;++i){
            visited[i]=0;
        }
        bfs.push(q);
        while (!bfs.empty()){
            uwu=bfs.front();
            bfs.pop();
            if (visited[uwu]==0){
                for (int i=0;i<graph[uwu].size();++i){
                    bfs.push(graph[uwu][i]);
                }
                visited[uwu]=1;
            }
        }
        if (visited[p]==1){
            cout << "no";
        }
        else {
            cout << "unknown";
        }
    }
    
}