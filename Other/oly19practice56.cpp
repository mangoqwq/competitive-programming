#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int M, N, U, F, D;
    cin >> M >> N >> U >> F >> D;
    string s; cin >> s;
    int ans = 0;
    for (char c : s){
        int cost;
        if (c == 'f') cost = 2 * F;
        else cost = U + D;
        if (cost > M) break;
        ans++;
        M -= cost;
    }
    cout << ans << '\n';
}
