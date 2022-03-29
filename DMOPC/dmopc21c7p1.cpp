#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1501;

int a[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            cin >> a[i][j];
            if (!a[i][j]) a[i][j] = max(a[i - 1][j], a[i][j - 1]) + 1;
        }
    }
    bool can = 1;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= M; ++j){
            can &= a[i][j] > max(a[i - 1][j], a[i][j - 1]);
        }
    }
    if (can){
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= M; ++j){
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }
    else{
        cout << -1 << '\n';
    }
}
