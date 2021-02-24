#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int arr[MAXN], dist[MAXN];
vector<int> adj[MAXN];
multiset<int> s;

void bfs(int src){
    ms(dist,0x3f);
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while (!q.empty()){
        int v=q.front(); q.pop();
        for (int to:adj[v]){
            if (dist[to]>dist[v]+1){
                dist[to]=dist[v]+1;
                q.push(to);
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, q; cin >> n >> m >> q;    
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        adj[b].push_back(a);
    }
    bfs(n);
    for (int i=1;i<=n;++i){
        int a; cin >> a;
        arr[i]=dist[a];
        s.insert(arr[i]+i-1);
    }
    while (q--){
        int a, b; cin >> a >> b;
        s.erase(s.lower_bound(arr[a]+a-1));
        s.erase(s.lower_bound(arr[b]+b-1));
        swap(arr[a],arr[b]);
        s.insert(arr[a]+a-1);
        s.insert(arr[b]+b-1);
        cout << *s.begin() << '\n';
    }
}