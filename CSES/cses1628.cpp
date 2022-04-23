#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X; cin >> N >> X;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    while (a.size() < 40) a.push_back(1e9 + 1);
    N = 40;
    ll ans = 0;
    vector<ll> l, r;
    for (int i = 0; i < (1 << 20); ++i){
        ll tot0 = 0, tot1 = 0;
        for (int j = 0; j < 20; ++j){
            if (1 & (i >> j)) tot0 += a[j], tot1 += a[j + 20];
        }
        l.push_back(tot0);
        r.push_back(tot1);
    }
    sort(r.begin(), r.end());
    for (auto x : l){
        ll need = X - x;
        ans += upper_bound(r.begin(), r.end(), need) - lower_bound(r.begin(), r.end(), need);
    }
    cout << ans << '\n';
}
