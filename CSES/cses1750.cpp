#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1, K = 29;

int nxt[MN][K + 1];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        int a; cin >> a;
        nxt[i][0] = a;
    }
    for (int b = 1; b <= K; ++b){
        for (int i = 1; i <= N; ++i){
            nxt[i][b] = nxt[nxt[i][b - 1]][b - 1];
        }
    }
    while (Q--){
        int x, k; cin >> x >> k;
        for (int i = K; i >= 0; --i){
            if ((1 << i) & k) x = nxt[x][i];
        }
        cout << x << '\n';
    }
}
