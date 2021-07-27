#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 1005;

int g[MAXN][MAXN];
int val[MAXN][MAXN];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            char c;
            cin >> c;
            if (c=='.') g[i][j] = 0;
            if (c=='C'){
                g[i][j] = 1;
                for (int s = 0; s < 4; ++s){
                    val[i + dx[s]][j + dy[s]]++;
                }
            }
            if (c=='G') g[i][j] = 2;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (g[i][j] == 2){
                if (val[i][j] < 2) continue;
                ans++;
                if (val[i][j] == 2 && val[i - 1][j - 1] == 2 && g[i - 1][j - 1] == 2 && g[i - 1][j] == 1 && g[i][j - 1] == 1)
                    ans--;
                if (val[i][j] == 2 && val[i - 1][j + 1] == 2 && g[i - 1][j + 1] == 2 && g[i - 1][j] == 1 && g[i][j + 1] == 1)
                    ans--;
            }
        }
    }
    cout << ans << '\n';
}
