#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, A, B; cin >> N >> A >> B;
    vector<double> dp(B + 10), lst(B + 10);
    dp[0] = 1;
    for (int i = 1; i <= N; ++i){
        swap(dp, lst); fill(dp.begin(), dp.end(), 0);
        for (int j = B; j >= 0; --j){
            for (int k = 1; k <= 6; ++k){
                dp[j + k] += lst[j];
            }
        }
    }
    double a = 0;
    for (int i = A; i <= B; ++i){
        a += dp[i];
    }
    double b = pow(6, N);
    cout << fixed << setprecision(6) << a / b << '\n';
}
