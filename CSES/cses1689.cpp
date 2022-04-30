#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    const int N = 8;
    const int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1};
    const int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};

    int sx, sy; cin >> sx >> sy; sx--, sy--; swap(sx, sy);
    vector<pair<int, int>> tour;
    vector<vector<int>> vis(N, vector<int>(N));
    function<bool(int, int)> valid = [&](int x, int y){
        return x >= 0 && x < N && y >= 0 && y < N;
    };
    function<int(int, int)> valids = [&](int x, int y){
        int cnt = 0;
        for (int i = 0; i < 8; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if (!valid(nx, ny)) continue;
            cnt += !vis[nx][ny];
        }
        return cnt;
    };
    bool found = 0;
    function<void(int, int)> dfs = [&](int x, int y){
        vis[x][y] = 1;
        tour.push_back({x, y});
        if (tour.size() == N * N){
            found = 1;
            return;
        }
        struct Item{ int x, y, c; };
        vector<Item> vec;
        for (int i = 0; i < 8; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if (!valid(nx, ny) || vis[nx][ny]) continue;
            vec.push_back({nx, ny, valids(nx, ny)});
        }
        sort(vec.begin(), vec.end(), [](Item a, Item b){ return a.c < b.c; });
        for (auto [nx, ny, nc] : vec){
            dfs(nx, ny);
            if (found) return;
        }
        vis[x][y] = 0;
        tour.pop_back();
    }; dfs(sx, sy);
    vector<vector<int>> ans(N, vector<int>(N));
    int T = 0;
    for (auto [x, y] : tour) ans[x][y] = ++T;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}
