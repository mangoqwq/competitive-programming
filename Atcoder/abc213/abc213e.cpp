#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 501;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bool block[MN][MN];
int dist[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            char c; cin >> c;
            if (c == '#') block[i][j] = 1;
        }
    }
    ms(dist, 0x3f);
    struct Pos{ int x, y; };
    deque<Pos> q;
    q.push_back({1, 1}); dist[1][1] = 0;
    while (!q.empty()){
        auto [x, y] = q.front(); q.pop_front();
        // cout << x << " " << y << " " << dist[x][y] << '\n';
        for (int e = 0; e < 4; ++e){
            int nx = x + dx[e], ny = y + dy[e];
            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (!block[nx][ny]){
                if (dist[nx][ny] > dist[x][y]){
                    dist[nx][ny] = dist[x][y];
                    q.push_front({nx, ny});
                }
            }
        }
        for (int i = x - 2; i <= x + 2; ++ i){
            for (int j = y - 2; j <= y + 2; ++j){
                if (i < 1 || i > N || j < 1 || j > M) continue;
                if (abs(i - x) + abs(j - y) == 4) continue;
                if (dist[i][j] > dist[x][y] + 1){
                    dist[i][j] = dist[x][y] + 1;
                    q.push_back({i, j});
                }
            }
        }
    }
    cout << dist[N][M] << '\n';
}
