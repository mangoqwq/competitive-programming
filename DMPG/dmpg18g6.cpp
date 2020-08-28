#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,int> plli;
int value[100001];
bool visited[100001];
vector<int> attend[100001];
vector<int> contain[100001];
ll dist[100001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    cout.sync_with_stdio(0);
    int students, classes, cost; cin >> students >> classes >> cost;
    for (int i=1;i<students+1;++i){
        cin >> value[i];
    }
    for (int i=1,a;i<students+1;++i){
        cin >> a;
        for (int k=0,x;k<a;++k){
            cin >> x;
            attend[i].push_back(x);
            contain[x].push_back(i);
        }
    }
    memset(dist,0x3f,sizeof dist);
    dist[1]=0; //visited[1]=1;
    priority_queue<plli, vector<plli>, greater<plli>> pq; ll uwu; int node;
    pq.push({dist[1],1});
    while (!pq.empty()){
        uwu=pq.top().first; node=pq.top().second; pq.pop();
        if (!visited[node]){
            visited[node]=1;
            for (auto&&a:attend[node]){
                for (auto&&x:contain[a]){
                    if (dist[node]+(abs(value[node]-value[x])+cost)<dist[x]){
                        dist[x]=dist[node]+(abs(value[node]-value[x])+cost);
                        if (!visited[x]){
                            pq.push({dist[x],x});
                        }
                    }
                }
            }
        }
    }
    for (int i=1;i<students+1;++i){
        if (dist[i]==0x3f3f3f3f3f3f3f3f){
            cout << -1 << '\n';
        }
        else{
            cout << dist[i] << '\n';
        }
    }

}