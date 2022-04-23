#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    using ll = long long;
    int N; cin >> N;
    vector<ll> twos(N);
    twos[0] = 0;
    for (int i = 1; i < N; ++i){
        twos[i] = twos[i - 1] + __builtin_ctz(i);
    }
    function<ll(int, int)> choose = [&](int n, int k){
        return twos[n] - twos[k] - twos[n - k];
    };
    int ans = 0;
    for (int i = 0; i < N; ++i){
        int a; cin >> a;
        if (!choose(N - 1, i)) ans ^= a;
    }
    cout << ans << '\n';
}
