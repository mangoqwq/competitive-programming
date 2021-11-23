#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 101;

int N, M, K;
int g[MN][MN];
char ans[MN][MN];
int calc(int x, int y){
    return g[x - 1][y - 1] - g[x - K + 1][y - 1] - g[x - 1][y - K + 1] + g[x - K + 1][y - K + 1];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cin >> ans[i][j];
            if (ans[i][j] == '*') g[i][j] = 1;
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
    }
    int bx = K, by = K;
    for (int i = K; i <= N; ++i){
        for (int j = K; j <= M; ++j){
            if (calc(i, j) > calc(bx, by)) bx = i, by = j;
        }
    }
    
    for (int i = bx - K + 1; i <= bx; ++i){
        for (int j = by - K + 1; j <= by; ++j){
            bool fx = (i == bx - K + 1) || (i == bx);
            bool fy = (j == by - K + 1) || (j == by);
            if (fx && fy) ans[i][j] = '+';
            else if (fx) ans[i][j] = '-';
            else if (fy) ans[i][j] = '|';
        }
    }
    cout << calc(bx, by) << '\n';
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cout << ans[i][j];
        }
        cout << '\n';
    }
}
