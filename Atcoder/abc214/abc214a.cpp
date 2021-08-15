#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    if (n <= 125) cout << 4 << '\n';
    else if (n <= 211) cout << 6 << '\n';
    else cout << 8 << '\n';
}
