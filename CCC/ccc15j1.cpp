#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int m, d; cin >> m >> d;
    if (m == 2 && d == 18) cout << "Special" << '\n';
    else if (m > 2 || (m == 2 && d > 18)) cout << "After" << '\n';
    else cout << "Before" << '\n';
}
