#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, O; cin >> N >> O;
    int mn = inf, mx = 0;
    for (int i = 1; i <= 200; ++i){
        if (i - i / N == O){
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    cout << mn << " " << mx << '\n';
}
