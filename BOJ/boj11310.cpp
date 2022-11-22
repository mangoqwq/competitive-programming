#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<string> g(N);
    for (int i = 0; i < N; ++i){
        cin >> g[i];
    }

    auto in = [&](int i, int j){
        return i >= 0 && j >= 0 && i < N && j < M;
    };

    using pii = pair<int, int>;
    vector<vector<int>> dist(N, vector<int>(M, 1e9));
    map<char, int> ans;
    queue<pii> q;

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            if (g[i][j] == 'W'){
                dist[i][j] = -1;
                q.push({i, j});
            }
            else ans[g[i][j]] = 1e9;
        }
    }

    while (!q.empty()){
        auto [x, y] = q.front(); q.pop();
        if (g[x][y] != 'W'){
            ans[g[x][y]] = min(ans[g[x][y]], dist[x][y]);
        }
        for (int i = 0; i < 8; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if (!in(nx, ny)) continue;
            int nd = dist[x][y] + (g[x][y] != g[nx][ny]);
            if (nd < dist[nx][ny]){
                dist[nx][ny] = nd;
                q.push({nx, ny});
            }
        }
    }

    for (auto [c, v] : ans){
        cout << c << " " << v << '\n';
    }
}
