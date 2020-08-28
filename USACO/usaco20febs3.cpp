#include <bits/stdc++.h>

using namespace std;
int uwu[2501];
int temp[2501];
vector<int> graph[2501];

void dfs(int node, int prev){

    for (auto&&x:graph[node]){
        if (x==prev) continue;
        dfs(x,node);
        temp[node]+= (24-temp[x]);
        temp[node]%=12;
    }
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int nodes,count=0; cin >> nodes;
    for (int i=1;i<nodes+1;++i){
        cin >> uwu[i];
    }
    for (int i=1,a,b;i<nodes;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i=1;i<nodes+1;++i){
        copy(begin(uwu),end(uwu),begin(temp));
        dfs(i,0);
        if (temp[i]%12==1||temp[i]%12==0){
            count++;
        }
    }
    cout << count << '\n';

}