#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1001;

ll g[MN][8], dp[2][MN][8];
int a[3];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    ms(dp, -0x3f);
    dp[1][0][7] = 0;
    for (int i = 1; i <= N; ++i){
        cin >> g[i][0] >> g[i][1] >> g[i][2];
    }
    for (int i = 1; i <= N; ++i){
        swap(dp[0], dp[1]), ms(dp[1], -0x3f);
        for (int j = 0; j <= K; ++j){
            for (int mask = 0; mask < 27; ++mask){
                int msk = mask;
                for (int x = 0; x <= 2; ++x) a[x] = msk % 3, msk /= 3;
                ll add = 0, dom = 0, cur = 0, need = 0;
                for (int x = 0; x <= 2; ++x){
                    if (a[x] == 1) add += g[i][x] + g[i - 1][x], dom++;
                    if (a[x] == 2) add += g[i][x];

                    if (a[x]) cur += (1 << x);
                    if (a[x] == 1) need += (1 << x);
                }

                if (a[0] == 2 && a[2] == 2) continue;
                if ((a[0] == 2 || a[2] == 2) && !(a[1] == 2)) continue;
                if ((a[1] == 2) && !(a[0] == 2 || a[2] == 2)) continue;
                if (a[1] == 2) dom++;

                if (j < dom) continue;
                for (int lst = 0; lst < 8; ++lst){
                    if (lst & need) continue;
                    dp[1][j][cur] = max(dp[1][j][cur], dp[0][j - dom][lst] + add);
                }
            }
        }
    }
    cout << *max_element(dp[1][K], dp[1][K] + 8) << '\n';
}
