#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1001;

int psa[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            char c; cin >> c;
            psa[i][j] = (c == '*') + psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= Q; ++i){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << psa[x2][y2] - psa[x2][y1 - 1] - psa[x1 - 1][y2] + psa[x1 - 1][y1 - 1] << '\n';
    }
}
