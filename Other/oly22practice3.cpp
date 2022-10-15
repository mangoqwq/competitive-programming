#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;
int a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    ll ans = 0;
    map<int, int> cnt;
    for (int i = 1; i <= N; ++i){
        int x; cin >> x; a[i] = x;
        for (int j = 1; j * j <= x; ++j){
            if (x % j) continue;
            cnt[j] ++;
            if (j * j != x) cnt[x / j]++;
        }
    }
    for (int i = 1; i <= N; ++i) ans += cnt[a[i]];
    cout << ans - N << '\n';
}
