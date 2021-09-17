#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 55;

char grid[MN][MN];
int n, g[MN][MN], sx, sy;
bool vis[MN][MN];

bool can(int l, int r){
    ms(vis, 0);
    if (g[sx][sy] < l || g[sx][sy] > r) return 0;
    vis[sx][sy] = 1;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while (!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for (int i = -1; i <= 1; ++i){
            for (int j = -1; j <= 1; ++j){
                if (!vis[x + i][y + j] && g[x + i][y + j] >= l && g[x + i][y + j] <= r){
                    vis[x + i][y + j] = 1;
                    q.push({x + i, y + j});
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (!vis[i][j] && grid[i][j] == 'K') return 0;
        }
    }
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    vector<int> mn;
    ms(g, 0x3f);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            char c; cin >> c; grid[i][j] = c;
            if (c == 'P') sx = i, sy = j;
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> g[i][j];
            mn.push_back(g[i][j]);
        }
    }
    sort(mn.begin(), mn.end());
    int ans = inf;
    for (auto l : mn){
        int lo = l, ri = mn.back(), mid;
        while (lo < ri){
            mid = (lo + ri) >> 1;
            if (can(l, mid)) ri = mid;
            else lo = mid + 1;
        }
        if (can(l, lo)){
            // if (lo - l == 1) cout << l << " " << lo << '\n';
            ans = min(ans, lo - l);
        }
    }
    cout << ans << '\n';
}
