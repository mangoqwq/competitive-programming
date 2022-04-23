#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1002;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};
const char dir[] = {'U', 'L', 'R', 'D'};

bool vis[MN][MN];
pair<int, int> lst[MN][MN];
char ans[MN][MN];
struct Tile{ int x, y, c; };

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    queue<Tile> q;
    int sx, sy;
    ms(vis, 1);
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            char c; cin >> c;
            if (c == 'A') sx = i, sy = j;
            if (c == 'M') q.push({i, j, 0});
            if (c == '.') vis[i][j] = 0;
        }
    }
    q.push({sx, sy, 1});
    while (!q.empty()){
        auto [x, y, c] = q.front(); q.pop();
        if (c == 1 && (x == 1 || x == N || y == 1 || y == M)){
            vector<char> vec;
            while (tie(x, y) != tie(sx, sy)){
                vec.push_back(ans[x][y]);
                tie(x, y) = lst[x][y];
            }
            reverse(vec.begin(), vec.end());
            cout << "YES" << '\n';
            cout << vec.size() << '\n';
            for (char c : vec) cout << c;
            cout << '\n';
            return 0;
        }
        for (int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if (vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            lst[nx][ny] = {x, y};
            ans[nx][ny] = dir[i];
            q.push({nx, ny, c});
        }
    }
    cout << "NO" << '\n';
}
