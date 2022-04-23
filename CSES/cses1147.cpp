#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> up(N + 1, vector<int>(M + 1));
    int ans = 0;
    for (int i = 1; i <= N; ++i){
        struct Item{ int h, i; };
        stack<Item> s; s.push({-1, 0});
        for (int j = 1; j <= M; ++j){
            char c; cin >> c;
            if (c == '.') up[i][j] = up[i - 1][j] + 1;
            else up[i][j] = 0;
            while (s.top().h >= up[i][j]){
                auto [h, k] = s.top(); s.pop();
                ans = max(ans, h * (j - s.top().i - 1));
            }
            s.push({up[i][j], j});
        }
        while (s.size() > 1){
            auto [h, j] = s.top(); s.pop();
            ans = max(ans, h * (M - s.top().i));
        }
    }
    cout << ans << '\n';
}
