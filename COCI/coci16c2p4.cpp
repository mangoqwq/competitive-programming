#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 101;

int ans[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    if (N % 2 == 1){
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= N; ++j){
                cout << (i - 1) * N + j << " ";
            }
            cout << '\n';
        }
    }
    else{
        if (N == 2){
            cout << -1 << '\n';
            return 0;
        }
        for (int i = 1; i <= N; ++i){
            if (i == N){
                int tot = ans[i - 1][1] * N;
                for (int r = 1; r < N; ++r) tot -= ans[r][1];
                ans[i][1] = tot;
            }
            else ans[i][1] = ans[i - 1][N] + 1;
            for (int j = 2; j <= N - 1; ++j){
                ans[i][j] = ans[i][j - 1] + 1;
            }
            ans[i][N] = ans[i][N - 1] * N - accumulate(ans[i] + 1, ans[i] + N, 0);
        }
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= N; ++j){
                cout << ans[i][j] << " ";
            }
            cout << '\n';
        }
    }
}
