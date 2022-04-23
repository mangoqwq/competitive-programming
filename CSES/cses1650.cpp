#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vector<ll> a(N + 1);
    for (int i = 1; i <= N; ++i) cin >> a[i], a[i] ^= a[i - 1];
    for (int i = 1; i <= Q; ++i){
        int l, r; cin >> l >> r;
        cout << (a[r] ^ a[l - 1]) << '\n';
    }
}
