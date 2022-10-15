#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int N, K; cin >> N >> K;
    int n = N / 2;
    if (K % 2 == 1 || K < 2 * n){
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    K = N * N - 1 - K;
    int r = n - 1, c = 3;
    int cor = 1;
    N--;
    vector<pair<int, int>> ans;
    for (r; r >= 0; --r){
        int val = 8 * r + c * 2;
        if (val > K){
            int nxt = c * r * 2 + (r * (r - 1)) / 2 * 8;
            if (nxt < K){
                r++;
                c--;
                continue;
            }
        }
        else{
            K -= val;
            int grid = cor + (4 - c - 1) * N + 1;
            if (val != 0) ans.push_back({grid, grid + val + 1});
        }
        cor += 4 * N;
        N -= 2;
    }

    sort(ans.begin(), ans.end());
    assert(!K);
    cout << ans.size() << '\n';
    for (auto [l, r] : ans){
        cout << l << " " << r << '\n';
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
