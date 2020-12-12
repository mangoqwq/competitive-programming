#include <bits/stdc++.h>
using namespace std;
long long n, W, dp[100000];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> W;
    for (int i = 0, x, y; i < n; i++){
        cin >> x >> y;
        for (int j = W; j >= x; j--){
            dp[j] = max(dp[j], dp[j - x] + y);
        }
    }
    cout << dp[W];
    return 0;
}