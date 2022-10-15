#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 101;

int N, M;
char g[MN][MN];
bool vis[MN][MN];

void print(){
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cout << g[i][j];
        }
        cout << '\n';
    }
}

void fix(){
    bool again = 0;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            while (g[i][j] == 'W' && g[i][j - 1] == '.'){
                again = 1;
                swap(g[i][j], g[i][j - 1]);
                j--;
            }
        }
    }

    ms(vis, 0);
    for (int j = 1; j <= M; ++j){
        for (int i = N; i >= 1; --i){
            if (g[i][j] == 'W' && g[i + 1][j] == '.'){
                again = 1;
                vis[i][j] = 1;
            }
        }
    }
    for (int j = 1; j <= M; ++j){
        for (int i = N; i >= 1; --i){
            if (vis[i][j]) swap(g[i + 1][j], g[i][j]);
        }
    }
    if (again) fix();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;
    for (int i = 0; i <= N + 1; ++i){
        for (int j = 0; j <= N + 1; ++j){
            g[i][j] = 'X';
        }
    }
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cin >> g[i][j];
        }
    }
    int Q; cin >> Q;
    while (Q--){
        int op; cin >> op;
        if (op == 1){
            for (int j = 1; j <= M; ++j){
                if (g[N][j] == 'X') g[N][j] = '.';
            }
            for (int i = N; i >= 2; --i){
                for (int j = 1; j <= M; ++j){
                    if (g[i][j] == 'X') g[i][j] = '.';
                    if (g[i - 1][j] == 'X'){
                        g[i][j] = 'X';
                    }
                }
            }
            for (int j = 1; j <= M; ++j){
                if (g[1][j] == 'X') g[1][j] = '.';
            }
            fix();
        }
        if (op == 2){
            print();
        }
    }
}
