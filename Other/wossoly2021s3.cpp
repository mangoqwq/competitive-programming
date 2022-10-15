#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 205;

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
struct Point{ int x, y; };
struct Edge{ int x, y, d; };
int dist[MN][MN];
Point dest[5];
vector<Edge> adj[MN][MN];
char g[MN][MN];
map<char, Point> out;

void bfs(int sx, int sy){
    ms(dist, 0x3f);
    dist[sx][sy] = 0;
    deque<Point> q; q.push_back({sx, sy});
    while (!q.empty()){
        auto [x, y] = q.front(); q.pop_front();
        for (auto [nx, ny, w] : adj[x][y]){
            if (dist[x][y] + w < dist[nx][ny]){
                dist[nx][ny] = dist[x][y] + w;
                if (w == 0) q.push_front({nx, ny});
                else q.push_back({nx, ny});
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 0; i <= N + 1; ++i){
        for (int j = 0; j <= M + 1; ++j){
            g[i][j] = '#';
        }
    }
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cin >> g[i][j];
            if (g[i][j] >= '0' && g[i][j] <= '4'){
                dest[g[i][j] - '0'] = {i, j};
                g[i][j] = '.';
            }
            if (g[i][j] >= 'a' && g[i][j] <= 'z'){
                out[g[i][j]] = {i, j};
            }
        }
    }
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            if (g[i][j] >= 'A' && g[i][j] <= 'Z'){
                Point to = out[g[i][j] - 'A' + 'a'];
                adj[i][j].push_back({to.x, to.y, 0});
            }
            else if (g[i][j] != '#'){
                for (int k = 0; k < 4; ++k){
                    int nx = i + dx[k], ny = j + dy[k];
                    if (g[nx][ny] != '#' && !(g[nx][ny] >= 'a' && g[nx][ny] <= 'z')){
                        adj[i][j].push_back({nx, ny, 1});
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= 4; ++i){
        bfs(dest[i - 1].x, dest[i - 1].y);
        ans += dist[dest[i].x][dest[i].y];
    }
    if (ans >= inf) cout << -1 << '\n';
    else cout << ans << '\n';
}
