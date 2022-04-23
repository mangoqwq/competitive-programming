#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int x[MN], pos[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        cin >> x[i];
        pos[x[i]] = i;
    }
    int ans = 1;
    for (int i = 2; i <= N; ++i){
        if (pos[i] < pos[i - 1]) ans++;
    }
    while (Q--){
        int i, j; cin >> i >> j;
        int a = x[i], b = x[j];
        if (a != 1) ans -= pos[a] < pos[a - 1];
        if (a != N) ans -= pos[a + 1] < pos[a];
        if (b != 1 && a != b - 1) ans -= pos[b] < pos[b - 1];
        if (b != N && a != b + 1) ans -= pos[b + 1] < pos[b];
        swap(pos[a], pos[b]); swap(x[i], x[j]);
        if (a != 1) ans += pos[a] < pos[a - 1];
        if (a != N) ans += pos[a + 1] < pos[a];
        if (b != 1 && a != b - 1) ans += pos[b] < pos[b - 1];
        if (b != N && a != b + 1) ans += pos[b + 1] < pos[b];
        cout << ans << '\n';
    }
}
