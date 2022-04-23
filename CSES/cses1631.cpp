#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;
ll a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + N);
    ll tot = accumulate(a + 1, a + 1 + N, 0LL);
    cout << max(tot, a[N] * 2) << '\n';
}
