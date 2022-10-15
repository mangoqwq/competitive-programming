#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll P, W, N; cin >> P >> W >> N;
    ll cntp = 0, cntw = 0, ans = 0;
    for (int i = 0; i < N; ++i){
        char c; cin >> c;
        int x; cin >> x;
        if (c == 'P') ans += P, cntp++;
        if (c == 'W') ans += W, cntw++;
    }
    ans -= cntp * cntw;
    cout << ans << '\n';
}
