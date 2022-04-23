#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1002;

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
char d[] = {'U', 'L', 'R', 'D'}, dir[MN][MN];
struct Point{ int x, y; } lst[MN][MN];
bool open[MN][MN];

void go(int sx, int sy){
    queue<Point> q; open[sx][sy] = 0;
    q.push({sx, sy});
    while (!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if (open[nx][ny]){
                open[nx][ny] = 0;
                lst[nx][ny] = {x, y};
                dir[nx][ny] = d[i];
                q.push({nx, ny});
            }
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    int sx = 0, sy = 0, ex = 0, ey = 0;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            char c; cin >> c;
            open[i][j] = c == '.' || c == 'A' || c == 'B';
            if (c == 'A') sx = i, sy = j;
            if (c == 'B') ex = i, ey = j;
        }
    }
    go(sx, sy);
    if (open[ex][ey]) cout << "NO" << '\n';
    else{
        cout << "YES" << '\n';
        string ans = "";
        while (ex != sx || ey != sy){
            ans += dir[ex][ey];
            Point p = lst[ex][ey];
            ex = p.x, ey = p.y;
        }
        cout << ans.size() << '\n';
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
    }
}
