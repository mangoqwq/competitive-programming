#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 5;

int a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    int cur = 0, T = 0;
    for (int i = 1; i <= N; ++i){
        char c; cin >> c;
        if (c == '0') cur++;
        if (c == '1') a[++T] = cur, cur = 0;
    }
    a[++T] = cur;
    sort(a + 1, a + 1 + T, greater<int>());
    int ans = 0;
    for (int i = 1; i <= K; ++i) ans += a[i];
    cout << ans << '\n';
}
