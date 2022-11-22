#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dp[21][21][21][21];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int H, W; cin >> H >> W;
    vector<vector<char>> g(H, vector<char>(W));
    for (int i = 0; i < H; ++i){
        for (int j = 0; j < W; ++j){
            cin >> g[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    auto mex = [&](set<int> s){
        for (int i = 0;;++i){
            if (!s.count(i)) return i;
        }
    };
    auto solve = [&](auto self, int x1, int y1, int x2, int y2) -> int{
        int &cur = dp[x1][y1][x2][y2];
        if (cur != -1) return cur;
        set<int> s;
        for (int i = x1; i < x2; ++i){
            for (int j = y1; j < y2; ++j){
                if (g[i][j] == 'X') continue;
                s.insert(self(self, x1, y1, i, j) ^
                         self(self, i+1, j+1, x2, y2) ^
                         self(self, i+1, y1, x2, j) ^
                         self(self, x1, j+1, i, y2));
            }
        }
        return cur = mex(s);
    };
    cout << (solve(solve, 0, 0, H, W) ? "First" : "Second");
}
