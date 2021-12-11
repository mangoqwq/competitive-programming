#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll A, B; cin >> A >> B;
    if (B % 2 == 1) B = B * 10;
    string ans = to_string(A) + "0" + to_string(B / 2);
    cout << ans << '\n';
}
