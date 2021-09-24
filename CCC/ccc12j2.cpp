#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c, d; cin >> a >> b >> c >> d;
    bool up = 1, down = 1;
    if (b >= a) down = 0;
    if (a >= b) up = 0;
    if (c >= b) down = 0;
    if (b >= c) up = 0;
    if (d >= c) down = 0;
    if (c >= d) up = 0;
    if (a == b && a == c && a == d) cout << "Fish At Constant Depth" << '\n';
    else if (down) cout << "Fish Diving" << '\n';
    else if (up) cout << "Fish Rising" << '\n';
    else cout << "No Fish" << '\n';
}
