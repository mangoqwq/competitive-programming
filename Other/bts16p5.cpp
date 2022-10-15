#include <iostream>
#include <queue>

using namespace std;

int main(){
    int nodes, cherries, yui;
    cin >> nodes >> cherries >> yui;
    int patches[nodes+1], temp; //ARRr im in charge now
    for (int i=1;i<nodes+1;++i){
        cin >> temp;
        patches[i]=temp;
    }
    vector<pair<int,int>> tree[nodes+1];
    int a, b, c;
    for (int i=0;i<nodes-1;++i){
        cin >> a >> b >> c;
        tree[a].push_back(make_pair(b,c));
        tree[b].push_back(make_pair(a,c));
    }

    int dist[nodes+1]={0},visited[nodes+1]={0},uwu,count=0,queuesize;
    pair<int,int> in[nodes+1];
    queue<int> q;
    q.push(1);
    dist[1]=0;
    visited[1]=1;
    while (!q.empty()){
        count++;
        queuesize=q.size();
        for (int i=0;i<queuesize;++i){
            uwu=q.front();
            q.pop();
            for (auto&&x:tree[uwu]){
                if (visited[x.first]==0){
                    visited[x.first]=1;
                    in[x.first]=make_pair(uwu,x.second);
                    dist[x.first]=count;
                    q.push(x.first); 
                }
            }
        }
    }
    count--;
    pair<int,int> aaa[nodes+1];
    for (int i=0;i<nodes+1;++i){
        aaa[i]=make_pair(0,0);
    }
    for (int k=count;k>0;--k){
        for (int i=1;i<nodes+1;++i){
            if (dist[i]==k){
                for (auto&&x:tree[i]){
                    aaa[i].first+=aaa[x.first].first;
                    aaa[i].second+=aaa[x.first].second;
                }
                aaa[i].first+=patches[i];
                aaa[i].second+=in[i].second;
            }
        }
    }
    int total=0;
    for (int i=0;i<nodes+1;++i){
        if (aaa[i].first>=cherries && aaa[i].second<=yui){
            total+=1;
        }
    }
    cout << total << '\n';
    

        
}