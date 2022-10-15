#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dir[] = {'S', 'E', 'N', 'W'};

void solve(){
    int N, M; cin >> N >> M;
    vector<vector<bool>> g(2 * N, vector<bool>(2 * M));
    vector<vector<bool>> vis(2 * N, vector<bool>(2 * M));
    int cnt = 0;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            char c; cin >> c;
            bool b = c == '*';
            cnt += b;
            g[2 * i][2 * j] = g[2 * i + 1][2 * j] = g[2 * i][2 * j + 1] = g[2 * i + 1][2 * j + 1] = b;
        }
    }
    function<bool(int, int)> valid = [&](int x, int y){
        if (x >= 0 && x < 2 * N && y >= 0 && y < 2 * M) return 1;
        return 0;
    };
    function<pair<int, int>(int, int)> getb = [&](int x, int y){
        return pair<int, int>{x / 2 * 2, y / 2 * 2};
    };
    vector<pair<int, int>> path;
    function<void(int, int, int)> dfs1 = [&](int x, int y, int lst){
        vis[x][y] = 1;
        path.push_back({x, y});
        cnt--;
        for (int j = -1; j < 3; ++j){
            int i = (lst + j + 4) % 4;
            int nx = x + 2 * dx[i], ny = y + 2 * dy[i];
            if (!valid(nx, ny)) continue;
            if (!g[nx][ny]) continue;
            if (vis[nx][ny]) continue;
            dfs1(nx, ny, i);
            path.push_back({x, y});
        }
    }; dfs1(0, 0, 0);
    if (cnt){
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    string ans = "";
    function<void(int, int, int, int)> dfs = [&](int x, int y, int idx, int lst){
        g[x][y] = 0;
        // cout << x << " " << y << " | ";
        cout.flush();
        for (int j = -1; j < 3; ++j){
            int i = (lst + j + 4) % 4;
            int nx = x + dx[i], ny = y + dy[i];
            if (!valid(nx, ny)) continue;
            if (!g[nx][ny]) continue;
            if (idx == path.size() - 1);
            if (getb(path[idx + 1].first, path[idx + 1].second) == getb(nx, ny)){
                ans += dir[i];
                dfs(nx, ny, idx + 1, i);
                return;
            }
        }
        for (int j = -1; j < 3; ++j){
            int i = (lst + j + 4) % 4;
            int nx = x + dx[i], ny = y + dy[i];
            if (!valid(nx, ny)) continue;
            if (!g[nx][ny]) continue;
            if (getb(nx, ny) == getb(x, y)){
                ans += dir[i];
                dfs(nx, ny, idx, i);
                return;
            }
        }
    }; dfs(0, 0, 0, 0);
    ans += 'W';
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
