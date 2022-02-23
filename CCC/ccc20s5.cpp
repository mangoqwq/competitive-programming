#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;
int a[MN], cnt[MN];
double dp[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    if (a[1] == a[N]){ return cout << 1 << '\n', 0; }
    double cur = 0;
    dp[a[N]] = 0; cnt[a[N]]++;
    for (int i = N - 1; i >= 1; --i){
        if (a[i] == a[1]) dp[a[i]] = 1;
        else if (cnt[a[i]] == 0) dp[a[i]] = (1 + cur) / (N - i + 1);
        cnt[a[i]]++; cur += dp[a[i]];
    }
    cout << fixed << setprecision(14) << cur / N << '\n';
}
