#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> graph[100001]; int valid[100001];

bool isgood(ll x){
    return x==floor(sqrtl(x))*(floor(sqrtl(x))+1);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int nodes; ll a,b; cin >> nodes;
    for (int i=1;i<nodes+1;++i){
        cin >> a;
        if (isgood(a)){
            valid[i]=1;
        }
    }
    for (int i=0;i<nodes-1;++i){
        cin >> a >> b;
        if (valid[a] && valid[b]){
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }
    priority_queue<int> pq; queue<int> q; int count, uwu, visited[100001]={0},visit[100001]; pq.push(0);
    for (int i=1;i<nodes+1;++i){
        if (!valid[i] || visited[i]){continue;}
        q.push(i); visited[i]=1;
        while (!q.empty()){
            uwu=q.front(); q.pop();
            for (auto&&x:graph[uwu]){
                if (!visited[x]){
                    visited[x]=1;
                    q.push(x);
                }
                
            }
        }
        count=0; q.push(uwu); memset(visit,0,sizeof visit); visit[uwu]=1;
        while (!q.empty()){
            int qsize=q.size(); count++;
            for (int _=0;_<qsize;++_){
                uwu=q.front(); q.pop();
                for (auto&&x:graph[uwu]){
                    if (!visit[x]){
                        visit[x]=1;
                        q.push(x);
                    }
                    
                }
            }
        }
        pq.push(count);
    }
    cout << pq.top() << '\n';
}