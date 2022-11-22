#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<string> g(N);
    for (int i = 0; i < N; ++i){
        cin >> g[i];
    }

    auto in = [&](int x, int y) -> bool{
        return min(x, y) >= 0 && max(x, y) < N;
    };

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if (g[i][j] == 'K'){
                for (int dx = -1; dx <= 1; ++dx){
                    for (int dy = -1; dy <= 1; ++dy){
                        int nx = i + dx, ny = j + dy;
                        if (!in(nx, ny)) continue;
                        if (g[nx][ny] == '*') g[nx][ny] = '?';
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if (g[i][j] != '-') continue;
            if (in(i-1, j-1) && g[i-1][j-1] == '*'){
                ans++;
                g[i-1][j-1] = '-';
                if (in(i-1, j+1)) g[i-1][j+1] = '-';
            }

            if (in(i-1, j+1) && g[i-1][j+1] == '*'){
                if (in(i, j+2) && g[i][j+2] == '-') continue;
                ans++;
                g[i-1][j+1] = '-';
            }
        }
    }

    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            if (g[i][j] == '*'){
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << ans << '\n';
}

/*
8
-*-*----
*-*-----
--------
--------
-----*K-
--------
--*-----
--------
*/
