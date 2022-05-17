#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vector<vector<int>> a(N + 2, vector<int>(M + 2));
    vector<vector<int>> vis(N + 2, vector<int>(M + 2));
    vector<int> par(N + 2), rowVis(N + 2);

    int cnt = 0;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            char c; cin >> c;
            a[i][j] = c == 'H';
            par[i] = (par[i] + a[i][j]) % 2;
        }
        cnt += par[i];
    }

    if ((cnt + N) % 2 || cnt == 0){
        cout << -1 << '\n';
        return 0;
    }

    auto flip = [&](int i, int j){
        if (!a[i][j]){
            cout << "BAD FLIP: " << i << " " << j << '\n';
            assert(false);
        }
        cout << i << " " << j << '\n';
        vis[i][j] = 1;
        a[i][j] ^= 1;
        a[i - 1][j] ^= 1, a[i + 1][j] ^= 1;
        a[i][j - 1] ^= 1, a[i][j + 1] ^= 1;
    };

    auto flipRow = [&](int r){
        int B = M;
        if (a[r][M]){
            flip(r, M);
            B--;
        }
        for (int i = 1; i <= B; ++i){
            if (a[r][i]){
                flip(r, i);
                for (int j = i - 1; j > 0; --j){
                    if (vis[r][j]) break;
                    flip(r, j);
                }
            }
        }
        par[r] ^= 1;
        par[r - 1] ^= 1, par[r + 1] ^= 1;
        rowVis[r] = 1; 
    };

    if (par[N]){
        flipRow(N);
        N--;
    }
    for (int i = 1; i <= N; ++i){
        if (par[i]){
            flipRow(i);
            for (int j = i - 1; j > 0; --j){
                if (rowVis[j]) break;
                flipRow(j);
            }
        }
    }
}
