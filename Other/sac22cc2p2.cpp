#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 501;

int a[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    int ans = 0;
    while (q--){
        int op; cin >> op;
        if (op == 1){
            int x, y; cin >> x >> y;
            a[x][y]++;
        }
        else{
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            for (int x = x1; x <= x2; ++x){
                for (int y = y1; y <= y2; ++y){
                    ans += a[x][y];
                }
            }
        }
    }
    cout << ans << '\n';
}
