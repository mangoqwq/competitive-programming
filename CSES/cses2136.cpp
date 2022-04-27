#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<int> a(N);
    int ans = K;
    for (int i = 0; i < N; ++i){
        string s; cin >> s;
        a[i] = stoull(s, 0, 2);
    }
    for (int i = 0; i < N; ++i){
        for (int j = i + 1; j < N; ++j){
            ans = min(ans, __builtin_popcount(a[i] ^ a[j]));
        }
    }
    cout << ans << '\n';
}
