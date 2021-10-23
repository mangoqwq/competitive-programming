#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 501, MC = 2e5 + 1;

int lst[MC], dp[MC];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    ms(lst, -0x3f);
    ms(dp, -0x3f); dp[0] = 0;
    int tot = 0;
    for (int i = 1; i <= N; ++i){
        swap(lst, dp); 
        int c; cin >> c; tot += c;
        for (int j = 0; j <= tot; ++j){
            dp[j] = max({lst[j], lst[j + c] + c, lst[abs(j - c)] + c});
        }
    }
    cout << tot - dp[0] / 2 << '\n';
}
