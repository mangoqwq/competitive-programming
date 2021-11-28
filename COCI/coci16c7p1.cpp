#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e3 + 1;

int a[MN][MN], b[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cin >> a[i][j];
        }
    }
    int Q; cin >> Q;
    while (Q--){
        for (int i = 1; i <= M; ++i){
            cin >> b[i];
        }
        int ans = 0;
        for (int i = 1; i <= N; ++i){
            bool good = 1;
            for (int j = 1; j <= M; ++j){
                if (b[j] == -1) continue;
                good &= a[i][j] == b[j];
            }
            ans += good;
        }
        cout << ans << '\n';
    }
}
