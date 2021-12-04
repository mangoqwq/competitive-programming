#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 501;

char g[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j) g[i][j] = '.';
        for (int j = i * 3; j < (i + 1) * 3; ++j){
            g[i][j % N] = '#';
        }
    }
    if (N % 3 == 1){
        swap(g[0][0], g[0][3]);
        swap(g[N / 3 * 2 + 1][0], g[N / 3 * 2 + 1][3]);
    }
    if (N % 3 == 2){
        swap(g[0][0], g[0][3]);
        swap(g[N / 3 + 1][0], g[N / 3 + 1][3]);
    }
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < N; ++j){
            cout << g[i][j];
        }
        cout << '\n';
    }
}
