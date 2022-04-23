#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1001;

int g[MN][MN], bit[MN][MN];
void ins(int x, int y, int val){
    // cout << i << " " << j << " " << val << '\n';
    for (int i = x; i < MN; i += i & -i){
        for (int j = y; j < MN; j += j & -j){
            bit[i][j] += val;
        }
    }
}
int qry(int x, int y){
    int ret = 0;
    for (int i = x; i; i -= i & -i){
        for (int j = y; j; j -= j & -j){
            ret += bit[i][j];
        }
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            char c; cin >> c;
            g[i][j] = (c == '*');
            if (g[i][j]) ins(i, j, 1);
        }
    }
    while (Q--){
        int op; cin >> op;
        if (op == 1){
            int x, y; cin >> x >> y;
            ins(x, y, (g[x][y] ? -1 : 1));
            g[x][y] ^= 1;
        }
        if (op == 2){
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            cout << qry(x2, y2) - qry(x2, y1 - 1) - qry(x1 - 1, y2) + qry(x1 - 1, y1 - 1) << '\n';
        }
    }
}
