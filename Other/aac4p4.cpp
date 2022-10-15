#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e3 + 1;

int k[MN], ans[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, S, F, L, R; cin >> N >> M >> S >> F >> L >> R;
    int idx = 0;
    for (int i = 1; i <= M; ++i){
        cin >> k[i];
        if (k[i] == F) idx = i;
    }
    if (idx == 0 && S != F){
        cout << -1 << '\n';
        return 0;
    }
    int cnt = 0;
    if (!(S == F && L == 0)){
        cnt = idx != 0; ans[1][idx] = 1;
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= M; ++j){
                if (i == F && j > idx) continue;
                if (ans[i][j]) continue;
                if (cnt == R) continue;
                ans[i][j] = 1; cnt++;
            }
        }
        int baton = S;
        for (int i = 1; i < idx; ++i){
            if (ans[baton][i]) baton = k[i];
        }
        swap(ans[baton][idx], ans[1][idx]);
    }
    if (cnt < L || cnt > R){
        cout << -1 << '\n';
        return 0;
    }
    cout << cnt << '\n';
    int tot = 0;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cout << ans[i][j] << (j == M ? '\n' : ' ');
        }
    }
}
