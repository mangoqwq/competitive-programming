#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1001;

ll m[MN], b[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) cin >> b[i] >> m[i];
    int ans = inf;
    for (int i = 1; i <= N; ++i){
        for (int j = i + 1; j <= N; ++j){
            if (m[j] == m[i]){
                if (b[i] == b[j]) ans = 0;
                continue;
            }
            if ((b[i] - b[j]) % (m[j] - m[i])) continue;
            int cur = (b[i] - b[j]) / (m[j] - m[i]);
            if (cur >= 0) ans = min(ans, cur);
        }
    }
    if (ans == inf) cout << -1 << '\n';
    else cout << ans << '\n';
}
