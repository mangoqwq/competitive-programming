#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int W, D, H; cin >> W >> D >> H;
        int a, b, c, d; cin >> a >> b >> c >> d;
        int ans = 1e9;
        ans = min(ans, a + c + abs(b-d));
        ans = min(ans, (W-a) + (W-c) + abs(b-d));
        ans = min(ans, b + d + abs(a-c));
        ans = min(ans, (D-b) + (D-d) + abs(a-c));
        cout << ans + H << '\n';
    }
}
