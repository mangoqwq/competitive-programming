#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 305;

int dp[MN][MN][MN];
bool vis[MN][MN][MN];
char g[MN][MN];
struct Point{ int x, y, k; };
vector<Point> q[MN];
int ans;
string str;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 0; i <= N; ++i){
        for (int j = 0; j <= M + 1; ++j){
            for (int k = 1; k <= N; ++k){
                dp[i][j][k] = -inf;
            }
        }
    }
    int sx, sy;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            char c; cin >> c;
            g[i][j] = c;
            for (int k = 0; k <= N; ++k){
                int &cur = dp[i][j][k];
                if (c == '.' || c == 'M'){
                    cur = max({dp[i - 1][j - 1][k], dp[i - 1][j][k], dp[i - 1][j + 1][k]});
                }
                if (c == ')'){
                    if (k == 0) continue;
                    cur = max({dp[i - 1][j - 1][k - 1], dp[i - 1][j][k - 1], dp[i - 1][j + 1][k - 1]}) + 1;
                }
                if (c == '('){
                    if (k == N) continue;
                    cur = max({dp[i - 1][j - 1][k + 1], dp[i - 1][j][k + 1], dp[i - 1][j + 1][k + 1]}) + 1;
                }
                if (c == 'M'){
                    sx = i, sy = j;
                }
            }
        }
    }
    ans = dp[sx][sy][0];
    cout << ans << '\n';
    q[0].push_back({sx, sy, 0});
    int last = 0;
    for (int i = 0; i <= ans; ++i){
        sort(q[i].begin(), q[i].end(), [](Point a, Point b){ return a.k < b.k; });
        int best = q[i].back().k;
        while (!q[i].empty() && i != ans){
            auto [x, y, k] = q[i].back(); q[i].pop_back();
            if (k != best) break;
            for (int j = -1; j <= 1; ++j){
                if (i + dp[x - 1][y + j][k] != ans) continue;
                if (vis[x - 1][y + j][i]) continue;
                vis[x - 1][y + j][i] = 1;
                if (g[x - 1][y + j] == '('){
                    q[i + 1].push_back({x - 1, y + j, k + 1});
                }
                else if (g[x - 1][y + j] == ')'){
                    q[i + 1].push_back({x - 1, y + j, k - 1});
                }
                else{
                    q[i].push_back({x - 1, y + j, k});
                }
            }
        }
        if (best > last) str += '(';
        if (best < last) str += ')';
        last = best;
    }
    cout << str << '\n';
}
