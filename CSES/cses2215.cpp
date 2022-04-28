#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, K; cin >> N >> K;
        if (K * K < N){
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }
        vector<int> ans = {-K + 1};
        for (int i = 0; i < N; ++i){
            if ((ans[i] - 1) % K == 0) ans.push_back(min(ans[i] + 2 * K - 1, N));
            else ans.push_back(ans[i] - 1);
            cout << ans.back() << " ";
        }
        cout << '\n';
    }
}
