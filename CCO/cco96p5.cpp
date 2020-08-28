#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
vector<int> graph[27];
int visited[27];

void print(stack<int> s){
    int x=s.size();
    vector<int> temp;
    for (int i=0;i<x;++i){
        temp.push_back(s.top());
        s.pop();
    }
    for (int i=temp.size()-1;i>-1;--i){
        cout << (char)(temp[i]+64);
    }
    cout << '\n';
}

void dfs(int node, int end, stack<int> path){
    if (node==end){
        print(path);
    }
    else{
        visited[node]=1;
        for (auto&&x:graph[node]){
            if (!visited[x]){
                path.push(x);
                dfs(x,end,path);
                path.pop();
            }
        }


    }

}

int main(){
    int roads,queries;
    cin >> roads >> queries;

    string a,b;
    for (int i=0;i<roads;++i){
        cin >> a >> b;
        graph[(int)a.at(0)-64].push_back((int)b.at(0)-64);
        graph[(int)b.at(0)-64].push_back((int)a.at(0)-64);
    }

    int start, end;
    for (int k=0;k<queries;++k){
        stack<int> path;
        for (int i=0;i<27;++i){
            visited[i]=0;
        }
        cin >> a >> b;
        start=(int)a.at(0)-64; end=(int)b.at(0)-64;
        path.push(start);
        dfs(start,end,path);
    }
}
