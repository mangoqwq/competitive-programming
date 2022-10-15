#include <iostream>
#include <queue>

using namespace std;

int main(){
    int vertices,edges;
    cin >> vertices >> edges;
    vector<pair<long long,long long>> graph[vertices+1];

    int a,b,c;
    for (int k=0;k<edges;++k){
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c)); //node, weight
        graph[b].push_back(make_pair(a,c));
    }

    long long dist[vertices+1];
    for (int i=0;i<vertices+1;++i){
        dist[i]=10000001;
    }
    dist[1]=0;
    for (int k=0;k<1001;++k){
        for (int i=1;i<vertices+1;++i){
            for (int l=0;l<graph[i].size();++l){
                dist[graph[i][l].first]=min(dist[graph[i][l].first],dist[i]+graph[i][l].second);
            }
        }
    }
    for (int i=1;i<vertices+1;++i){
        if (dist[i]>=10000001){
            cout << -1 << '\n';
        }
        else{
        cout << dist[i] << '\n';
        }
    }

    
}