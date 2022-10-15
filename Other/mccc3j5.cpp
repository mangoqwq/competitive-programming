#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1000;

int a[MN], b[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; ++i) cin >> a[i] >> b[i], a[i]--, b[i]--;
    int ans = 0;
    for (int i = 0; i < (1 << N); ++i){
        bool bad = 0;
        for (int j = 1; j <= M; ++j){
            if ((1 & (i >> a[j])) && (1 & (i >> b[j]))) bad = 1;
        }
        if (!bad){
            ans = max(ans, __builtin_popcount(i));
        }
    }
    cout << ans << '\n';
}
