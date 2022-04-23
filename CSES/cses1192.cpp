#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1002;

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
struct Point{ int x, y; };
bool open[MN][MN];

void flood(int sx, int sy){
    queue<Point> q; open[sx][sy] = 0;
    q.push({sx, sy});
    while (!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if (open[nx][ny]){
                open[nx][ny] = 0;
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            char c; cin >> c;
            open[i][j] = c == '.';
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            if (open[i][j]){
                ans++;
                flood(i, j);
            }
        }
    }
    cout << ans << '\n';
}
