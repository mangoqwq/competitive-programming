#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 1;
int dp[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X; cin >> N >> X;
    vector<int> a(N);
    for (int &x : a) cin >> x;
    ms(dp, 0x3f), dp[0] = 0;
    for (int i = 1; i <= X; ++i){
        for (int x : a){
            if (x <= i) dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }
    cout << (dp[X] == inf ? -1 : dp[X]) << '\n';
}
