#include <iostream>
#include <queue>

using namespace std;

vector<int> graph[1001];
int ans[1001][1001];

void bfs(int node){
    int visited[1001]={0},uwu,count=1;
    queue<int> q;
    q.push(node);
    while (!q.empty()){
        int length=q.size();
        for (int i=0;i<length;++i){
            uwu=q.front();
            visited[uwu]=1;
            q.pop();
            for (auto&&x:graph[uwu]){
                if (visited[x]==0){
                    q.push(x);
                    if (ans[node][x]!=-1){
                        ans[node][x]=min(ans[node][x],count);
                    }
                    else{
                        ans[node][x]=count;
                    }
                }
            }
        }
        count++;
    }
}

int main(){
    int nodes,edges,time,a,b;
    cin >> nodes >> edges >> time;
    for (int i=0;i<edges;++i){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i=0;i<1001;++i){
        for (int k=0;k<1001;++k){
            ans[i][k]=-1;
        }
    }
    for (int i=1;i<nodes+1;++i){
        bfs(i);
    }
    int queries;
    cin >> queries;
    for (int i=0;i<queries;++i){
        cin >> a >> b;
        if (ans[a][b]==-1){
            cout << "Not enough hallways!" << '\n';
        }
        else{
            cout << ans[a][b]*time << '\n';
        }
    }
}