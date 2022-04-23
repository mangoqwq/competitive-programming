#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<int> p(K);
    vector<int> dp(N + 1);
    for (int &x : p) cin >> x;
    for (int i = 1; i <= N; ++i){
        for (int x : p){
            if (x <= i) dp[i] |= !dp[i - x];
        }
        cout << (dp[i] ? 'W' : 'L');
    }
    cout << '\n';
}
