#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1, Z = 1e5;

bitset<MN> dp[126];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    dp[0][Z] = 1;
    for (int i = 1; i <= N; ++i){
        char c; cin >> c;
        int x = c - 'A' + 1; x *= x;
        for (int i = 125; i > 0; --i) dp[i] |= dp[i - 1] << x;
        for (int i = 0; i < 125; ++i) dp[i] |= dp[i + 1] >> x;
    }
    cout << dp[0].count() << '\n';
    for (int i = 0; i < MN; ++i){
        if (dp[0][i]){
            cout << i - Z << '\n';
        }
    }
}
