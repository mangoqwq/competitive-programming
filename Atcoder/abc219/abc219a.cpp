#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int x; cin >> x;
    if (x >= 90) cout << "expert" << '\n';
    else if (x >= 70) cout << 90 - x << '\n';
    else if (x >= 40) cout << 70 - x << '\n';
    else cout << 40 - x << '\n';
}
