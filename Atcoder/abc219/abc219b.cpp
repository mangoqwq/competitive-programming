#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

string s[4];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= 3; ++i) cin >> s[i];
    string op; cin >> op;
    string ans = "";
    for (char c : op) ans += s[c - '0'];
    cout << ans << '\n';
}
