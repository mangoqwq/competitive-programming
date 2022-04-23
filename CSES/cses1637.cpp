#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;
int dp[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    ms(dp, 0x3f); dp[0] = 0;
    for (int i = 1; i <= N; ++i){
        string s = to_string(i);
        for (char c : s){
            c -= '0';
            if (c <= i) dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
    cout << dp[N] << '\n';
}
