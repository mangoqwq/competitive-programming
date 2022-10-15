#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 11;

int N, ans = inf;
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
char g[MN][MN][MN];
void solve(int k){
    bool alive = 0;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            alive |= g[i][j][k] == 'A';
        }
    }
    if (!alive){
        ans = min(ans, k);
        return;
    }
    if (k == N) return;
    for (int dir = 0; dir < 4; ++dir){
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= N; ++j){
                if (g[i][j][k] == 'W') g[i][j][k + 1] = 'W';
                else{
                    int nx = i + dx[dir], ny = j + dy[dir];
                    if (g[nx][ny][k] == 'A') g[i][j][k + 1] = 'A';
                    else g[i][j][k + 1] = 'L';
                }
            }
        }
        solve(k + 1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            cin >> g[i][j][0];
        }
    }
    solve(0);
    cout << ans << '\n';
}
