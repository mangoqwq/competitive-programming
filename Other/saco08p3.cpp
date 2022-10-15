#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pair<bool,int>> piii;
typedef long long ll;
const int mod=1000000;
int graph[701][701]; int n,m; 
bool visited[2][701];
pii dist[2][701];
bool cookies[701];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i){
        for (int k=1;k<=n;++k){
            cin >> graph[i][k];
        }
    }
    cin >> m;
    for (int i=0,a;i<m;++i){
        cin >> a;
        cookies[a]=true;
    }
    memset(dist,0x3f,sizeof dist); dist[cookies[1]][1]={0,1};
    priority_queue<piii,vector<piii>,greater<piii>> pq; pq.push({0,{cookies[1],1}}); int d; bool c; int node;
    while (!pq.empty()){
        d=pq.top().first; c=pq.top().second.first; node=pq.top().second.second; pq.pop();
        if (!visited[c][node]){
            //cout << node << " " << d << " " <<  c << " "<< dist[c][node].second << '\n';
            visited[c][node]=1;
            for (int i=1;i<=n;++i){
                if (i==node) continue;
                bool ce=c||cookies[i];
                if (dist[ce][i].first>d+graph[node][i]){
                    dist[ce][i]={d+graph[node][i],dist[c][node].second};
                    if (!visited[c][i]){
                        pq.push({dist[ce][i].first,{ce,i}});
                    }
                }
                else if (dist[ce][i].first==d+graph[node][i]){
                    dist[ce][i].second+=dist[c][node].second;
                    dist[ce][i].second%=mod;
                }
            }
        }
    }
    cout << dist[1][n].first << " " << dist[1][n].second%mod << '\n';
    //cout << dist[1][n] << '\n';
}