#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 5;

ll a[MN];
ll sum(int l, int r){ return a[r] ^ a[l - 1]; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        a[N + 1] ^= a[i];
    }
    N++;
    for (int i = 1; i <= N; ++i) a[i] ^= a[i - 1];
    int Q; cin >> Q;
    while (Q--){
        ll l, r; cin >> l >> r;
        l = (l - 1) % N + 1;
        r = (r - 1) % N + 1;
        if (l > r) cout << (a[N] ^ sum(r + 1, l - 1)) << '\n';
        else cout << sum(l, r) << '\n';
    }
}
