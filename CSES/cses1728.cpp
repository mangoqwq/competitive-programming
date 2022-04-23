#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    double ans = 0;
    for (int i = 0; i < N; ++i){
        for (int j = i + 1; j < N; ++j){
            ans += 1.0 * (min(a[i], a[j]) * (min(a[i], a[j]) - 1) / 2 + max(0, a[i] - a[j]) * a[j]) / (a[i] * a[j]);
        }
    }
    cout << fixed << setprecision(6) << ans << '\n';
}
