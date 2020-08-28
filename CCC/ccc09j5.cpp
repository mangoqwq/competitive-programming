#include <iostream>
#include <queue>
#include <set>

using namespace std;
vector<int> graph[51]={{}, {6}, {6}, {4, 5, 6, 15}, {3, 5, 6}, {3, 4, 6}, {1, 2, 3, 4, 5, 7}, {6, 8}, {7, 9}, {8, 10, 12}, 
{9, 11}, {10, 12}, {9, 11, 13}, {12, 14, 15}, {13}, {3, 13}, {17, 18}, {16, 18}, {16, 17}};

int index(int person, int value){
    for (int i=0;i<graph[person].size();++i){
        if (graph[person][i]==value){
            return i;
        }
    }
    return -1;
}
vector<int> newgraph(int a, int b){
    vector<int> output;
    for (int i=0;i<graph[a].size();++i){
        if (i!=b){
            output.push_back(graph[a][i]);
        }
    }
    return output;
}


int main(){
    for (int i=20;i<51;++i){
        graph[i]={};
    }
    char command;
    int x,y;
    while (true){
        cin >> command;
        if (command=='i'){
            cin >> x >> y;
            if (index(x,y)<0){
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
        }
        else if (command=='d'){
            cin >> x >> y;
            if (index(x,y)>0){
                graph[x]=newgraph(x,index(x,y));
                graph[y]=newgraph(y,index(y,x));
            }
        }
        else if (command=='n'){
            cin >> x;
            cout << graph[x].size() << '\n';
        }
        else if (command=='f'){
            cin>>x;
            queue<int> q;
            int visited[51];
            for (int i=0;i<51;++i){
                visited[i]=0;
            }
            set<int> two;
            visited[x]=1;
            for (int i=0;i<graph[x].size();++i){
                q.push(graph[x][i]);
                visited[graph[x][i]]=1;
            }
            int uwu;
            while (!q.empty()){
                uwu=q.front();
                q.pop();
                for (int i=0;i<graph[uwu].size();++i){
                    if (visited[graph[uwu][i]]==0){
                        two.insert(graph[uwu][i]);
                    }
                }
            }
            cout << two.size() << '\n';
        }
        else if (command=='s'){
            cin>>x>>y;
            queue<int> q;
            int visited[51];
            for (int i=0;i<51;++i){
                visited[i]=0;
            }
            q.push(x);
            int uwu,count=0,end=0;
            while (end==0){
                if (q.empty()){
                    end=1;
                    break;
                }
                else{
                    int temp=q.size();
                    count+=1;
                    for (int i=0;i<temp;++i){
                        uwu=q.front();
                        q.pop();
                        for (int k=0;k<graph[uwu].size();++k){
                            if (visited[graph[uwu][k]]==0){
                                q.push(graph[uwu][k]);
                            }
                            if (graph[uwu][k]==y){
                                end=1;
                                visited[y]=1;
                            }
                        }
                        visited[uwu]=1;
                    }

                }
            }
            if (visited[y]==0){
                cout << "Not connected" << '\n';
            }
            else{
                cout << count << '\n';
            }

        }
        else if (command=='q'){
            break;
        }
    }
}