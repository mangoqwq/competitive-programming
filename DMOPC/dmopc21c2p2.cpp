#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 301;

int f[MN], idx[MN], ans[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    iota(f + 1, f + 1 + N, 1);
    iota(idx + 1, idx + 1 + N, 1);
    while (Q--){
        char op; cin >> op;
        if (op == 'E'){
            int i, j; cin >> i >> j;
            swap(f[i], f[j]);
            swap(idx[f[i]], idx[f[j]]);
        }
        if (op == 'B'){
            int i, j; cin >> i >> j;
            i = idx[i], j = idx[j];
            swap(f[i], f[j]);
            swap(idx[f[i]], idx[f[j]]);
        }
        if (op == 'Q'){
            for (int i = 1; i <= N; ++i) cin >> ans[i];
            for (int i = 1; i <= N; ++i){
                cout << ans[idx[i]] << (i == N ? '\n' : ' ');
            }
        }
    }
}
