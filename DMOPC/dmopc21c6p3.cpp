#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e3 + 1;
const int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

int c[MN][MN];
struct Point{ int x, y; };

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, K; cin >> N >> M >> K;
    vector<Point> cur, lst;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cin >> c[i][j];
            if (c[i][j]) cur.push_back({i, j});
        }
    }
    sort(cur.begin(), cur.end(), [&](Point a, Point b){ return c[a.x][a.y] < c[b.x][b.y]; });
    for (int i = 1; i <= K; ++i){
        swap(cur, lst); cur.clear();
        for (auto [x, y] : lst){
            for (int dir = 0; dir < 4; ++dir){
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
                if (c[nx][ny]) continue;
                c[nx][ny] = c[x][y];
                cur.push_back({nx, ny});
            }
        }
    }
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cout << c[i][j] << " ";
        }
        cout << '\n';
    }
}
