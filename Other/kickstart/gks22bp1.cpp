#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll R, A, B; cin >> R >> A >> B;
    double ans = 0;
    for (int i = 1; i <= 1e5; ++i){
        ans += R * R;
        R *= A;
        ans += R * R;
        R /= B;
    }
    cout << fixed << setprecision(7) << ans * acos(-1) << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
