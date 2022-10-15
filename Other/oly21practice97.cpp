#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<int> x(N + 1);
    for (int i = 1; i <= N; ++i){
        cin >> x[i];
    }
    ll ans = LLONG_MAX;
    for (int i = 1; i + K - 1 <= N; ++i){
        ll cur = min(abs(0 - x[i + K - 1]) + abs(x[i + K - 1] - x[i]),
                     abs(0 - x[i]) + abs(x[i + K - 1] - x[i]));
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}
