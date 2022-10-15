#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    double l, h, w; cin >> l >> h >> w;
    double d; cin >> d;
    cout << fixed << setprecision(12) << l * h * w - (3.1415926 * h * (d / 2) * (d / 2)); 
}
