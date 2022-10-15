#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

map<char, pii> mp = {
    {'N', {-1, 0}},
    {'E', {0, 1}},
    {'S', {1, 0}},
    {'W', {0, -1}},
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<char>> g(N, vector<char>(M));
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            cin >> g[i][j];
        }
    }
    vector<vector<bool>> vis(N, vector<bool>(M));
    int x = 0, y = 0, ans = 0;
    while (true){
        vis[x][y] = 1;
        if (g[x][y] == 'T'){
            cout << ans << '\n';
            break;
        }
        else{
            ans++;
            char cur = g[x][y];
            x += mp[cur].first;
            y += mp[cur].second;
            if (x < 0 || x >= N || y < 0 || y >= M){
                cout << "Out" << '\n';
                break;
            }
            else if (vis[x][y]){
                cout << "Lost" << '\n';
                break;
            }
        }
    }
}
