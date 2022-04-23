#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    ll ans = 0;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i){
        ll f;
        cin >> a[i] >> f;
        ans += f;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < N; ++i) a[i] += a[i - 1];
    cout << ans - accumulate(a.begin(), a.end(), 0LL);
}
