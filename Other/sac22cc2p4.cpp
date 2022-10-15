#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1005;

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int dist[MN][MN], g[MN][MN];
int N, M;
struct Point{ int x, y; };

void bfs(){
    deque<Point> q;
    ms(dist, 0x3f);
    q.push_back({1, 1});
    dist[1][1] = g[1][1];
    while (!q.empty()){
        auto [x, y] = q.front(); q.pop_front();
        for (int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || nx > N || ny <= 0 || ny > M) continue;
            if (dist[x][y] + g[nx][ny] < dist[nx][ny]){
                if (g[nx][ny]){
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push_back({nx, ny});
                }
                else{
                    dist[nx][ny] = dist[x][y];
                    q.push_front({nx, ny});
                }
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            char c; cin >> c;
            g[i][j] = c == 'C';
        }
    }
    bfs();
    cout << dist[N][M] << '\n';
}
