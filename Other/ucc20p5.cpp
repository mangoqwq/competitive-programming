#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1001;

vector<int> graph[MAXN];
int dist[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,start,end,m; cin >> n >> start >> end >> m;
    for (int i=0,a,b;i<m;++i){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    ms(dist,-1); int cnt=0,curr;
    queue<int> q; q.push(start);
    while (!q.empty()){
        int qsize=q.size();
        for (int i=0;i<qsize;++i){
            curr=q.front(); q.pop();
            dist[curr]=cnt;
            for (int x:graph[curr]){
                if (dist[x]==-1) q.push(x);
            }
        }
        cnt++;
    }
    cout << dist[end] << '\n';

}