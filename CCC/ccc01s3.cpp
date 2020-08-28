#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int graph[26][26];

int bfs(){
    queue<int> line;
    line.push(0);
    int visited[26];
    visited[0] = 1;
    for (int i=1;i<26;++i){
        visited[i] = 0;
    }   
    while (!line.empty()){
        int x=line.front();
        line.pop();
        for (int i=0;i<26;++i){
            if (graph[x][i] == 1){
                if (visited[i]==0){
                    visited[i]=1;
                    line.push(i);
                }
            }
        }
    }
    if (visited[1] == 0){
        return true;
    } else{
        return false;
    }

}

int ascii(char x){
    return (int)x-65;
}

int main(){
    for (int i=0;i<26;++i){
        for (int j=0;j<26;++j){
            graph[i][j]=0;
        }
    }
    string temp;
    while (true){
        getline(cin,temp);
        if (temp != "**"){
            graph[ascii(temp[0])][ascii(temp[1])]=1;
            graph[ascii(temp[1])][ascii(temp[0])]=1;
        } else {
            break;
        }
    }
    vector<string> disconnecting;
    for (int i=0;i<26;++i){
        for (int j=0;j<26;++j){
            if (graph[i][j]==1){
                graph[i][j]=0;
                graph[j][i]=0;

                if (bfs()){
                    string x(1,((char)('A'+i)));
                    string y(1,((char)('A'+j)));
                    if (std::find(disconnecting.begin(),disconnecting.end(),y+x)==disconnecting.end()){
                        disconnecting.push_back(x+y);
                    }  
                }

                graph[i][j]=1;
                graph[j][i]=1;
            }
                
        }
    }
    for (int i=0;i<disconnecting.size();++i){

    }
    for (int i=0;i<disconnecting.size();++i){
        cout<<disconnecting[i]<<'\n';
    }
    cout << "There are " <<disconnecting.size()<<" disconnecting roads." << '\n';
    return 0;

}