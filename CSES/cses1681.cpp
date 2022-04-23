#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

int deg[MN], ord[MN], T;
ll cnt[MN];
vector<int> adj[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }
    queue<int> q;
    for (int i = 1; i <= N; ++i){
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()){
        int v = q.front(); q.pop();
        ord[++T] = v;
        for (int to : adj[v]){
            deg[to]--;
            if (deg[to] == 0) q.push(to);
        }
    }
    cnt[N] = 1;
    for (int i = N; i >= 1; --i){
        int v = ord[i];
        for (int to : adj[v]){
            cnt[v] = (cnt[v] + cnt[to]) % mod;
        }
    }
    cout << cnt[1] << '\n';
}
