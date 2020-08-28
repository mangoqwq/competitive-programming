#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// Dfs, small to large trick

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

ll b[MAXN],c[MAXN],l[MAXN],n;ll budget;
vector<int> graph[MAXN];
ll ans=-1;

void bfs(int node, priority_queue<ll> &pq, ll &uwu){
    priority_queue<ll> curr; curr.push(c[node]);
    ll cost=c[node];
    for (int x:graph[node]){
        bfs(x,curr,cost);
    }
    //cout << node << "->";
    ans=max(ans,(ll)curr.size()*l[node]);
    if (curr.size()>pq.size()){swap(pq,curr);swap(uwu,cost);}
    while (!curr.empty()){
        //cout << curr.top() << ":" << uwu << "|";
        if (curr.top()+uwu<=budget){
            uwu+=curr.top();
            pq.push(curr.top());
        }
        else if (curr.top()<pq.top()){
            uwu-=pq.top();
            uwu+=curr.top();
            pq.pop(); pq.push(curr.top());
        }
        curr.pop();
    }
    //cout << '\n';
    //cout << "--> " << node << " " << cnt << " " << l[node] << '\n';
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> budget;
    for (int i=1;i<=n;++i){
        cin >> b[i] >> c[i] >> l[i];
        graph[b[i]].push_back(i);
    }
    priority_queue<ll> temp; ll temp2=0;
    bfs(1,temp,temp2);
    cout << ans << '\n';
}