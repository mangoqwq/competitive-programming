#include <bits/stdc++.h>

using namespace std;
vector<int> graph[100001];
int degree[100001], visited[100001];

int n,r;


int main(){
    for (int __=0;__<10;++__){
        for (int i=0;i<n+1;++i){
            graph[i].clear();
        }
        memset(degree,0,sizeof degree); memset(visited,0,sizeof visited);
        cin >> n >> r;
        for (int i=0,a,b;i<n-1;++i){
            cin >> a >> b;
            graph[a].push_back(b);
            degree[b]++;
        }
        queue<int> q;
        for (int k=1;k<n+1;++k){
            if (degree[k]==0){
                visited[k]=1; q.push(k);
                
            }
        }










    }
}