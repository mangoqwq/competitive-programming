#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, div2 = (mod + 1) / 2;
const int MN = 3e3 + 1, MK = 1e6 + 1;

ll N, M, K;
bool gen[MN];
ll single[MN], multi[MN];
ll tsingle, tmulti;
int dist[MN];
vector<int> adj[MN];
ll ans[MK], sz[MK], d1[MK];
ll gens;

void bfs(int src){
    ms(dist, 0x3f);
    dist[src] = 0;
    queue<int> q; q.push(src);
    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int to : adj[v]){
            if (dist[v] + 1 < dist[to]){
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    for (int i = 1; i <= N; ++i){
        if (gen[i]) multi[src] += dist[i];
        else single[src] += dist[i];
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i){
        cin >> gen[i];
        gens += gen[i];
    }
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= N; ++i){
        bfs(i);
        ans[1] = (ans[1] + single[i] + multi[i]) % mod;
        if (gen[i]) tsingle = (tsingle + single[i]) % mod;
        if (gen[i]) tmulti = (tmulti + multi[i]) % mod;
    }
    ans[1] = (ans[1] * div2) % mod;
    d1[1] = single[1] + multi[1];
    sz[1] = N;
    for (int i = 2; i <= K; ++i){
        sz[i] = (sz[i - 1] * gens + sz[1]) % mod;
        d1[i] = (d1[1] + gens * (d1[i - 1] + sz[i - 1]) % mod + (sz[i - 1] * (multi[1])) % mod) % mod;
        ans[i] = gens * (ans[i - 1] + (sz[i] - sz[i - 1] + mod) % mod * (d1[i - 1] + sz[i - 1]) % mod) % mod;
        ans[i] = (ans[i] + (sz[i - 1] * sz[i - 1] % mod * tmulti % mod * div2 % mod) + (sz[i - 1] * (tsingle + tmulti) % mod) + ans[1]) % mod;
    }
    assert(ans[K] >= 0);
    cout << ans[K] << '\n';
}
