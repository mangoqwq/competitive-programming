#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> up(N + 1, vector<int>(M + 1));
    vector<vector<int>> ans(N + 2, vector<int>(M + 2));
    for (int i = 1; i <= N; ++i){
        struct Item{ int h, i; };
        stack<Item> s; s.push({0, 0});
        for (int j = 1; j <= M + 1; ++j){
            char c;
            if (j <= M) cin >> c;
            if (c == '.' && j <= M) up[i][j] = up[i - 1][j] + 1;
            else up[i][j] = 0;
            while (s.top().h > up[i][j]){
                auto [h, k] = s.top(); s.pop();
                k = s.top().i + 1;
                int nh = max(up[i][j], s.top().h);
                ans[h][1]++, ans[h][j - k + 1]--;
                ans[nh][1]--, ans[nh][j - k + 1]++;
            }
            if (s.top().h < up[i][j]){
                s.push({up[i][j], j});
            }
            else if (s.top().h == up[i][j]) s.top().i = j;
        }
    }
    for (int i = 1; i <= N + 1; ++i){
        for (int j = 1; j <= M + 1; ++j){
            ans[i][j] += ans[i][j - 1];
        }
    }
    for (int i = N; i > 0; --i){
        for (int j = M; j > 0; --j){
            ans[i][j] += ans[i + 1][j] + ans[i][j + 1] - ans[i + 1][j + 1];
        }
    }
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}
