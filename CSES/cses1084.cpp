#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int a[MN], b[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, K; cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= M; ++i) cin >> b[i];
    sort(a + 1, a + 1 + N);
    sort(b + 1, b + 1 + M);
    int pl = 1, pr = 1, ans = 0;
    for (int i = 1; i <= M; ++i){
        while (pr <= N && a[pr] - K <= b[i]) pr++;
        while (pl <= N && a[pl] + K < b[i]) pl++;
        if (pl < pr) ans++, pl++;
    }
    cout << ans << '\n';
}
