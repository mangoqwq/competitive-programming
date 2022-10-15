#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;
ll a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    a[0] = 1;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        a[i] = lcm(a[i], a[i - 1]);
        if (a[i] > inf) a[i] = inf;
    }
    while (Q--){
        int x; cin >> x;
        int lo = 0, hi = N;
        while (lo < hi){
            int mid = (lo + hi + 1) >> 1;
            if (x % a[mid] == 0) lo = mid;
            else hi = mid - 1;
        }
        if (lo == N) cout << -1 << '\n';
        else cout << lo + 1 << '\n';
    }
}
