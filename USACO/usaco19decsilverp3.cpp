#include <bits/stdc++.h>

using namespace std;
char type[100001];
vector<int> graph[100001];
int group[100001],curr=1,visited[100001];

void dfs(int node,int prev){
    if (type[node]==type[prev]){
        group[node]=group[prev];
    }
    else{
        curr++;
        group[node]=curr;
    }
    for (auto&&x:graph[node]){
        if (!visited[x]&&x!=prev){
            dfs(x,node);
        }
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int nodes, queries,a,b; cin >> nodes >> queries;
    char temp;
    for (int i=1;i<nodes+1;++i){
        cin >> temp;
        type[i]=temp;
    }
    for (int i=0;i<nodes-1;++i){
        cin >> a >> b;
        graph[a].push_back(b); graph[b].push_back(a);
    }
    group[0]=1; type[0]=type[1];
    visited[1]=1; dfs(1,0);
    
    for (int i=0;i<queries;++i){
        cin >> a >> b >> temp;
        if (type[a]!=temp&&group[a]==group[b]){
            cout << 0;
        }
        else{
            cout << 1;
        }
    }
    cout << '\n';
}