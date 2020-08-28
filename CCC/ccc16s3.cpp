#include <bits/stdc++.h>

using namespace std;
vector<int> tree[100000]; vector<int> newtree[100000]; int ispho[100000]; int removeable[100000]; int visited[100000];

int dfs(int node){
    int needed=0;
    visited[node]=1;
    for (auto&&x:tree[node]){
        if (!visited[x]){
            if (dfs(x)==1){
                needed=1;
            }
        }
    }
    if (ispho[node]){
        needed=1;
    }
    removeable[node]=(!needed);
    return needed;

}

int main(){
    int nodes,phos,temp,a,b; cin >> nodes >> phos;
    for (int i=0;i<phos;++i){cin>>temp;ispho[temp]=1;}
    for (int i=0;i<nodes-1;++i){cin>>a>>b;tree[a].push_back(b);tree[b].push_back(a);}
    dfs(temp);

    int totaledges=0,start;
    for (int i=0;i<nodes;++i){
        if (!removeable[i]){
            start=i;
            for (int x:tree[i]){
                if (!removeable[x]){
                    
                    newtree[i].push_back(x);
                    totaledges++;
                }
            }
        }
    }
    queue<int> q;
    q.push(start); memset(visited,0,sizeof visited); int uwu;
    while (!q.empty()){
        uwu=q.front();q.pop();
        for (auto&&x:newtree[uwu]){
            if (!visited[x]){
                q.push(x);
                visited[x]=1;
            }
        }
    }
    q.push(uwu); memset(visited,0,sizeof visited); int count=-1; visited[uwu]=1;
    while (!q.empty()){
        int qsize=q.size();
        for (int i=0;i<qsize;++i){
            uwu=q.front(); q.pop();
            for (auto&&x:newtree[uwu]){
                if (!visited[x]){
                    q.push(x);
                    visited[x]=1;
                }
            }
        }
        count++;
    }
    //cout << totaledges << " - " << count << '\n';
    cout << totaledges-count << '\n';

}