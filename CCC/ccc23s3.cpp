#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, R, C; cin >> N >> M >> R >> C;
    vector<vector<char>> v(N, vector<char>(M, 'z'));

    auto bad = [&](){ cout << "IMPOSSIBLE" << '\n'; exit(0); };

    auto color = [&](int i, int j, char c){
        if (i < R || j < C) v[i][j] = 'a';
        else v[i][j] = c;
    };

    auto neq = [&](char a, char b){
        for (char c = 'a'; c <= 'z'; ++c){
            if (c != a && c != b) return c;
        }
        assert(false);
    };


    if (N == R){
        if (M % 2 == 0 && C % 2 == 1) bad();
        int dif = M - C;
        for (int j = 0; j < dif/2; ++j){
            v[0][j] = v[0][M-j-1] = 'a';
        }
        if (dif % 2) v[0][M/2] = 'a';
    }
    else if (M == C){
        if (N % 2 == 0 && R % 2 == 1) bad();
        int dif = N - R;
        for (int i = 0; i < dif/2; ++i){
            v[i][0] = v[N-i-1][0] = 'a';
        }
        if (dif % 2) v[N/2][0] = 'a';
    }
    else{
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                if ((i < R || j < C) && v[i][j] == 'z'){
                    v[i][j] = 'a';
                    color(i, M-j-1, 'b');
                    color(N-i-1, j, 'c');
                    color(N-i-1, M-j-1, 'd');
                }
                else if (v[i][j] == 'z'){
                    v[i][j] = neq(v[i][M-j-1], v[N-i-1][j]);
                }
            }
        }
    }
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            cout << v[i][j];
        }
        cout << '\n';
    }
}
