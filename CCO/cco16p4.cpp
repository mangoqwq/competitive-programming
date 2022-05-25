#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, G; cin >> N >> G;
    map<int, int> mp;
    for (int i = 1; i <= G; ++i){
        vector<vector<int>> v(N, vector<int>(N));
        for (int x = 0; x < N; ++x) for (int y = 0; y < N; ++y){
            char c; cin >> c;
            v[x][y] = c == 'W';
        }
        for (int x = N - 1; x >= 1; --x){
            for (int y = N - 1; y >= 1; --y){
                if (v[x][y]){
                    v[x][y] ^= 1;
                    v[x - 1][y] ^= 1;
                    v[x][y - 1] ^= 1;
                    v[x - 1][y - 1] ^= 1;
                }
            }
        }
        int val = 0;
        for (int x = 0; x < N; ++x){
            val = val * 2 + v[0][x];
        }
        for (int x = 1; x < N; ++x){
            val = val * 2 + v[x][0];
        }
        mp[val]++;
    }
    int ans = 0;
    for (auto [val, cnt] : mp){
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << '\n';
}
