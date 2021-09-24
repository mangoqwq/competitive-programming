#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<double> m(N + 1), v(N + 1);
    for (int i = 1; i <= N; ++i) cin >> m[i];
    double tot = 0;
    for (int i = N; i >= 2; --i){
        v[i] = m[i] / (m[i] + tot);
        tot += m[i];
    }
    for (int i = 2; i <= N; ++i){
        v[i] += v[i - 1];
    }
    double ans = v[N], cur; tot = 0;
    for (int i = N; i >= 2; --i){
        cur = 1 + v[i - 1] + tot / (m[i] + tot);
        ans = max(ans, cur);
        tot += m[i];
    }
    cout << fixed << setprecision(14) << ans << '\n';
}
