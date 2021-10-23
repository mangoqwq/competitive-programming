#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

vector<int> ans;
vector<int> adj[MN];
int deg[MN];
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        deg[b]++;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= N; ++i){
        if (deg[i] == 0) pq.push(i);
    }
    while (!pq.empty()){
        int v = pq.top(); pq.pop();
        ans.push_back(v);
        for (int to : adj[v]){
            deg[to]--;
            if (deg[to] == 0){
                pq.push(to);
            }
        }
    }
    if (ans.size() == N){
        for (int x : ans){
            cout << x << " ";
        }
        cout << '\n';
    }
    else{
        cout << -1 << '\n';
    }
}
