#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;
int deg[MN], a[MN], t[MN];
vector<int> adj[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> a[i]; t[i] = a[i];
        int c; cin >> c;
        while (c--){
            int x; cin >> x;
            deg[i]++;
            adj[x].push_back(i);
        }
    }
    queue<int> q;
    for (int i = 1; i <= N; ++i){
        if (deg[i] == 0) q.push(i);
    }
    int ans = 0;
    while (!q.empty()){
        int v = q.front(); q.pop();
        ans = max(ans, t[v]);
        for (int to : adj[v]){
            t[to] = max(t[to], a[to] + t[v]);
            deg[to]--;
            if (deg[to] == 0){
                q.push(to);
            }
        }
    }
    cout << ans << '\n';
}
