#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    const int L = 20;
    const int all = (1 << L) - 1;
    int N; cin >> N;
    vector<int> dp(1 << L), dp2(1 << L);
    vector<int> a(N);
    for (int i = 0; i < N; ++i){
        cin >> a[i];
        dp[a[i]]++;
        dp2[all ^ a[i]]++;
    }
    for (int i = 0; i < L; ++i) for (int j = 0; j < (1 << L); ++j){
        if (1 & (j >> i)){
            dp[j] += dp[j - (1 << i)], dp2[j] += dp2[j - (1 << i)];
        }
    }
    for (int i = 0; i < N; ++i){
        cout << dp[a[i]] << " ";
        cout << dp2[a[i] ^ all] << " ";
        cout << N - dp[a[i] ^ all] << '\n';
    }
}
