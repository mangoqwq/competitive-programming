#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 702;
const set<char> all = {'1', '2', '3', '4', '5'};

char g[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 0; i <= N + 1; ++i){
        for (int j = 0; j <= M + 1; ++j){
            g[i][j] = '.';
        }
    }
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            if (g[i][j] != '.') continue;
            set<char> can = all;
            for (int dx = -1; dx <= 1; ++dx){
                for (int dy = -1; dy <= 1; ++dy){
                    if (abs(dx) + abs(dy) != 1) continue;
                    can.erase(g[i + dx][j + dy]);
                }
            }
            g[i][j] = *can.begin();
        }
    }
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cout << g[i][j];
        }
        cout << '\n';
    }
}
