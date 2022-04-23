#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;
struct Eve{ int x, c; };

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<Eve> eves;
    for (int i = 1; i <= N; ++i){
        int l, r; cin >> l >> r;
        eves.push_back({l, 1});
        eves.push_back({r, -1});
    }
    sort(eves.begin(), eves.end(), [](Eve a, Eve b){ return a.x < b.x; });
    int ans = 0, cur = 0;
    for (auto [x, c] : eves){
        cur += c;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}
