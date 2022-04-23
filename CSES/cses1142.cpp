#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    struct Item{ int i, h; };
    stack<Item> s; s.push({0, -inf});
    vector<int> a(N + 2);
    for (int i = 1; i <= N; ++i) cin >> a[i];
    ll ans = 0;
    for (int i = 1; i <= N + 1; ++i){
        while (s.top().h > a[i]){
            int nh = s.top().h; s.pop();
            ans = max(ans, 1LL * nh * (i - s.top().i - 1));
        }
        s.push({i, a[i]});
    }
    cout << ans << '\n';
}
