#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    int ans = 0;
    for (int i = 1; i <= N; ++i){
        char c; cin >> c;
        if (K == 0) ans++;
        if (c == 'U') K--;
        if (c == 'D') K++;
        K = max(K, 0);
    }
    if (K == 0) ans++;
    cout << ans << '\n';
}
