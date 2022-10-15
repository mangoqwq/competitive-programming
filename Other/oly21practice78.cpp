#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 101;

int N, h[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> h[i];
    int ans = inf;
    for (int center = -100; center <= 100; ++center){
        int tot = 0;
        for (int i = 1; i <= N; ++i){
            tot += (h[i] - center) * (h[i] - center);
        }
        ans = min(ans, tot);
    }
    cout << ans << '\n';
}
