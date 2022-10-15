#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1, B = 1e7;

ll N, ans;
int cnt[(int)2e7 + 1], a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i], a[i] += a[i - 1];
    for (int j = 1; j <= 100; ++j){
        for (int i = 0; i <= N; ++i) ans += cnt[a[i] - j * i + B]++;
        for (int i = 0; i <= N; ++i) cnt[a[i] - j * i + B]--;
    }
    cout << ans << '\n';
}
