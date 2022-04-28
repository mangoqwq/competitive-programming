#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    function<int(int, int, int)> solve = [&](int n, int k, int s) -> int{
        if (s == 1){
            if (n % 2 == 0){
                if (k <= n / 2) return 2 * k - 1;
                return 2 * solve(n / 2, k - n / 2, 1);
            }
            if (n % 2 == 1){
                if (k <= n / 2 + 1) return 2 * k - 1;
                return 2 * solve(n / 2, k - n / 2 - 1, 2);
            }
        }
        if (s == 2){
            if (n % 2 == 0){
                if (k <= n / 2) return 2 * k;
                return 2 * solve(n / 2, k - n / 2, 2) - 1;
            }
            if (n % 2 == 1){
                if (k <= n / 2) return 2 * k;
                return 2 * solve(n / 2 + 1, k - n / 2, 1) - 1;
            }
        }
    };
    int T; cin >> T;
    while (T--){
        int N, K; cin >> N >> K;
        cout << solve(N, K, 2) << '\n';
    }
}
