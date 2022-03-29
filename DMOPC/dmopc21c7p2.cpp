#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 5;

int nxt[MN], lst[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    for (int i = 0; i <= N; ++i){
        nxt[i] = i + 1;
        lst[i + 1] = i;
    }
    while (Q--){
        int l, r, k; cin >> l >> r >> k;
        int a = lst[l], b = nxt[r], c = nxt[k];
        if (l == c) continue;
        nxt[a] = b; lst[b] = a;
        nxt[k] = l; lst[l] = k;
        nxt[r] = c, lst[c] = r;
    }
    int i = 0;
    for (int j = 1; j <= N; ++j){
        i = nxt[i];
        cout << i << " ";
    }
    cout << '\n';
}
