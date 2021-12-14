#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 504;

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
struct Point{ int x, y; };
struct Item{
    int x, y, dist;
    bool operator<(const Item &other) const{
        return dist > other.dist;
    }
};
struct Edge{ int x, y, w; };
vector<Edge> adj[MN][MN];
int dist[MN][MN], flood[MN][MN];
char g[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    Point ns, nt;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cin >> g[i][j];
            if (g[i][j] == 'C') ns = {i, j}, g[i][j] = '.';
            if (g[i][j] == 'F') nt = {i, j}, g[i][j] = '.';
        }
    }
    queue<Point> q;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            for (int k = 0; k < 4; ++k){
                if (g[i][j] == '.' && g[i + dx[k]][j + dy[k]] == '.'){
                    adj[i][j].push_back({i + dx[k], j + dy[k], 1});
                }
                if (g[i][j] == '#') q.push({i, j});
                else flood[i][j] = inf;
            }
        }
    }
    while (!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k){
            int nx = x + dx[k], ny = y + dy[k];
            if (flood[x][y] + 1 < flood[nx][ny]){
                flood[nx][ny] = flood[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    for (int i = 1; i <= N; ++i){
        Point last;
        for (int j = 1; j <= M; ++j){
            if (g[i][j] == '#') last = {i, j};
            else adj[i][j].push_back({last.x, last.y + 1, flood[i][j]});
        }
        for (int j = M; j >= 1; --j){
            if (g[i][j] == '#') last = {i, j};
            else adj[i][j].push_back({last.x, last.y - 1, flood[i][j]});
        }
    }
    for (int j = 1; j <= M; ++j){
        Point last;
        for (int i = 1; i <= N; ++i){
            if (g[i][j] == '#') last = {i, j};
            else adj[i][j].push_back({last.x + 1, last.y, flood[i][j]});
        }
        for (int i = N; i >= 1; --i){
            if (g[i][j] == '#') last = {i, j};
            else adj[i][j].push_back({last.x - 1, last.y, flood[i][j]});
        }
    }
    ms(dist, 0x3f);
    dist[ns.x][ns.y] = 0;
    priority_queue<Item> pq;
    pq.push({ns.x, ns.y, 0});
    while (!pq.empty()){
        auto [x, y, d] = pq.top(); pq.pop();
        for (auto [nx, ny, w] : adj[x][y]){
            if (d + w < dist[nx][ny]){
                dist[nx][ny] = d + w;
                pq.push({nx, ny, dist[nx][ny]});
            }
        }
    }
    if (dist[nt.x][nt.y] == inf) cout << "nemoguce" << '\n';
    else cout << dist[nt.x][nt.y] << '\n';
}
