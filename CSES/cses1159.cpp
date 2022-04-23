#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X; cin >> N >> X;
    struct Item{ int w, v; };
    vector<Item> items;
    vector<int> h(N + 1), s(N + 1), k(N + 1);
    for (int i = 1; i <= N; ++i) cin >> h[i];
    for (int i = 1; i <= N; ++i) cin >> s[i];
    for (int i = 1; i <= N; ++i) cin >> k[i];
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= k[i]; j *= 2){
            items.push_back({j * h[i], j * s[i]});
            k[i] -= j;
        }
        if (k[i]){
            items.push_back({k[i] * h[i], k[i] * s[i]});
        }
    }
    vector<int> dp(X + 1);
    for (auto [w, v] : items){
        for (int i = X; i >= w; --i){
            dp[i] = max(dp[i], dp[i - w] + v);
        }
    }
    cout << dp[X] << '\n';
}
