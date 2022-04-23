#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

double dp[8][8][8][8], lst[8][8][8][8];
double dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int K; cin >> K;
    function<bool(int, int)> valid = [&](int x, int y){
        return x >= 0 && x < 8 && y >=0 && y < 8;
    };
    for (int i = 0; i < 8; ++i) for (int j = 0; j < 8; ++j){
        dp[i][j][i][j] = 1;
        for (int _ = 0; _ < K; ++_){
            swap(dp[i][j], lst[i][j]);
            ms(dp[i][j], 0);
            for (int x = 0; x < 8; ++x) for (int y = 0; y < 8; ++y){
                int cnt = 4;
                if (x == 0 || x == 7) cnt--;
                if (y == 0 || y == 7) cnt--;
                for (int dir = 0; dir < 4; ++dir){
                    int nx = x + dx[dir], ny = y + dy[dir];
                    if (valid(nx, ny)){
                        dp[i][j][nx][ny] += lst[i][j][x][y] / cnt;
                    }
                }
            }
        }
    }
    double ans = 0;
    for (int i = 0; i < 8; ++i) for (int j = 0; j < 8; ++j){
        double prob = 1;
        for (int x = 0; x < 8; ++x) for (int y = 0; y < 8; ++y){
            prob *= (1 - dp[x][y][i][j]);
        }
        ans += prob;
    }
    cout << fixed << setprecision(6) << ans << '\n';
}
