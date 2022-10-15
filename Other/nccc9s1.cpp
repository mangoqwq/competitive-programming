#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

bool solve(){
    int a, b, c; cin >> a >> b >> c;
    if (b % 2 == 1 && a && c) a--, b--, c--;
    if (a < c) return 0;
    if ((a - c) % 2) return 0;
    if (b % 2 && a - c == 0) return 0;
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
