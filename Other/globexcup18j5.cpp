#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int N,M,Q,C;
vector<int> uwu[100000];
int dist[100000];

void bfs(){
    queue<int> q;
    int visited[100000];
    for (int i=0;i<100000;++i){
        visited[i]=0;
    }
    visited[C-1]=1;
    q.push(C-1);
    dist[C-1]=0;

    int counter=1,temp,node;
    while (!q.empty()){
        temp = q.size();
        for (int i=0; i<temp;++i){
            node=q.front();
            q.pop();
            for (int i=0;i<uwu[node].size();++i){
                if (visited[uwu[node][i]]==0){
                    visited[uwu[node][i]]=1;
                    dist[uwu[node][i]]=counter;
                    q.push(uwu[node][i]);
                }
            }
            
        }
        counter++;
    }
}

int main(){
    cin >> N >> M >> Q >> C;
    int a,b;
    for (int i=0;i<100000;++i){
        dist[i]=-1;
    }
    for (int i=0;i<M;++i){
        cin >> a >> b;
        uwu[a-1].push_back(b-1);
        uwu[b-1].push_back(a-1);
    }
    bfs();
    int _,__;
    for (int i=0;i<Q;++i){
        cin >> _ >> __;
        _--;
        __--;
        if (dist[_]>=0 && dist[__]>=0){
            cout << dist[_]+dist[__] << '\n';
        }
        else{
            cout << "This is a scam!" << '\n';
        }
    }
    

    

}