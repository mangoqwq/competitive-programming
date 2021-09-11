#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 301, MM = MN * MN / 2;

int a[MM], b[MM], flag[MM];

void solve(int l, int r){
    if (l == r) return;
    int m = (l + r) >> 1;
    cout << "? " << m - l + 1 << " " << r - m << '\n';
    for (int i = l; i <= m; ++i) cout << i << (i == m ? '\n' : ' ');
    for (int i = m + 1; i <= r; ++i) cout << i << (i == r ? '\n' : ' ');
    int c; cin >> c;
    for (int i = 1; i <= c; ++i){
        int x; cin >> x;
        flag[x] = 1;
    }
    solve(l, m), solve(m + 1, r);
}

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; ++i) cin >> a[i] >> b[i];
    solve(1, N);
    cout << "! ";
    for (int i = 1; i <= M; ++i){
        if (flag[i] && a[i] > b[i]) swap(a[i], b[i]);
        if (!flag[i] && a[i] < b[i]) swap(a[i], b[i]);
    }
    for (int i = 1; i <= M; ++i){
        // cout << flag[i] << " " << (a[i] > b[i]) << ": ";
        if (a[i] < b[i]) cout << 0;
        else cout << 1;
        // cout << '\n';
    }
    cout << '\n';
}
