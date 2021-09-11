#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 401;

int N, M;
struct Edge{ int to, id; };
vector<Edge> adj[MN];
int bad[MN * MN], ans;

int go(int block, int save = 0){
    queue<int> q;
    vector<int> dist(N + 1, inf);
    vector<int> last(N + 1), lastid(N + 1);
    q.push(1); dist[1] = 0;
    while (!q.empty()){
        int v = q.front(); q.pop();
        for (auto [to, id] : adj[v]){
            if (id == block) continue;
            if (dist[v] + 1 < dist[to]){
                dist[to] = dist[v] + 1;
                last[to] = v;
                lastid[to] = id;
                q.push(to);
            }
        }
    }
    if (dist[N] == inf){
        if (save) ans = -1;
        return -1;
    }
    if (save){
        int v = N;
        while (v){
            bad[lastid[v]] = 1;
            v = last[v];
        }
        ans = dist[N];
    }
    return dist[N];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back({b, i});
    }
    go(-1, 1);
    for (int i = 1; i <= M; ++i){
        if (bad[i]) cout << go(i) << '\n';
        else cout << ans << '\n';
    }
}
