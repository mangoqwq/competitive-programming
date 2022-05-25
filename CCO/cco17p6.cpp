#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Grid = vector<vector<int>>;
struct Point{ int x, y; };

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<Point> pos(N * M);

    struct Move{ int dir, x, r; };
    vector<Move> moves;

    auto right_shift= [&](Grid &g, int i, int r){
        Grid tmp = g;
        for (int j = 0; j < M; ++j){
            g[i][j] = tmp[i][(j - r + M) % M];
            pos[g[i][j]] = {i, j};
        }
        moves.push_back({0, i, r});
    };

    auto down_shift = [&](Grid &g, int j, int r){
        Grid tmp = g;
        for (int i = 0; i < N; ++i){
            g[i][j] = tmp[(i - r + N) % N][j];
            pos[g[i][j]] = {i, j};
        }
        moves.push_back({1, j, r});
    };

    auto move_to = [&](Grid &g, int x1, int y1, int x2, int y2){
        if (x1 == x2){
            right_shift(g, x1, (y2 - y1 + M) % M);
        }
        else if (y1 == y2){
            down_shift(g, y1, (x2 - x1 + N) % N);
        }
        else assert(false);
    };

    auto print = [&](const Grid &g){
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                cout << g[i][j] << " ";
            }
            cout << '\n';
        }
    };

    Grid s(N, vector<int>(M));
    Grid t(N, vector<int>(M));

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            cin >> s[i][j];
            pos[s[i][j]] = {i, j};
            t[i][j] = i * M + j;
        }
    }

    Grid init = s;

    // fix row 0 to N - 2
    for (int i = 0; i < N - 1; ++i){
        for (int j = 0; j < M; ++j){
            int id = t[i][j];
            if (pos[id].x == i){
                int col = pos[id].y;
                down_shift(s, col, 1);
                right_shift(s, pos[id].x, 1);
                down_shift(s, col, N - 1);
            }
            move_to(s, pos[id].x, pos[id].y, pos[id].x, (j + 1) % M);
            move_to(s, i, j, pos[id].x, j);
            move_to(s, pos[id].x, pos[id].y, pos[id].x, j);
            move_to(s, pos[id].x, pos[id].y, i, j);
        }
    }


    for (int i = N - 1, j = 0; j < M - 1; ++j){
        int id = t[i][j];
        if (pos[id].x == N - 1){
            if (pos[id].y == M - 1) move_to(s, pos[id].x, pos[id].y, N - 1, 0);
            move_to(s, N - 2, M - 1, N - 1, M - 1);
            move_to(s, N - 1, pos[id].y, N - 1, M - 1);
            move_to(s, N - 1, M - 1, N - 2, M - 1);
        }
        if (j) move_to(s, N - 1, pos[id - 1].y, N - 1, M - 2);
        move_to(s, N - 2, M - 1, N - 1, M - 1);
        move_to(s, N - 1, M - 1, N - 1, j);
        move_to(s, N - 1, M - 1, N - 2, M - 1);
    }


    if (s[N - 1][M - 1] != t[N - 1][M - 1]){
        down_shift(s, M - 1, 1);
        for (int i = 0; i < N - 2; i += 2){
            move_to(s, i, M - 1, i, M - 2);
            move_to(s, i, M - 2, i + 2, M - 2);
            move_to(s, i + 2, M - 2, i + 2, M - 1);
            move_to(s, i + 2, M - 1, i + 3, M - 1);
            move_to(s, i + 2, M - 1, i + 2, M - 2);
            move_to(s, i + 2, M - 2, i, M - 2);
            move_to(s, i + 2, M - 1, i + 1, M - 1);
            move_to(s, i, M - 2, i, M - 1);
        }
    }


    cout << moves.size() << '\n';
    vector<Move> ans = moves;
    for (auto [dir, x, r] : ans){
        cout << dir + 1 << " " << x + 1 << " " << r << '\n';
    }
}
