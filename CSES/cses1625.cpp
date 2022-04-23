#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 9;

string s;
bool vis[MN][MN];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}, dir[] = {'U', 'L', 'D', 'R'};
int lt[] = {1, 2, 3, 0}, rt[] = {3, 0, 1, 2};
int ans = 0;
void dfs(int x, int y, int idx, int last){
    if (x == 7 && y == 1){
        if (idx == 48) ans++;
        return;
    }
    else{
        int l = lt[last], r = rt[last];
        if (vis[x + dx[last]][y + dy[last]] && !vis[x + dx[l]][y + dy[l]] && !vis[x + dx[r]][y + dy[r]]){
            return;
        }
        vis[x][y] = 1;
        for (int i = 0; i < 4; ++i){
            int nx = x + dx[i], ny = y + dy[i];
            if (vis[nx][ny]) continue;
            if (!(s[idx] == '?' || dir[i] == s[idx])) continue;
            dfs(nx, ny, idx + 1, i);
        }
        vis[x][y] = 0;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ms(vis, 1);
    for (int i = 1; i <= 7; ++i){
        for (int j = 1; j <= 7; ++j){
            vis[i][j] = 0;
        }
    }
    cin >> s;
    dfs(1, 1, 0, 0);
    cout << ans << '\n';
}
