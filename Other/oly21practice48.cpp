#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    ll ans = 0;
    vector<ll> vec(N);
    for (ll &x : vec) cin >> x, x = max(x, 0LL);
    sort(vec.begin(), vec.end(), greater<ll>());
    for (int i = 1; i < N; ++i) vec[i] += vec[i - 1];
    while (Q--){
        int k; cin >> k;
        cout << vec[k - 1] << '\n';
    }
}
