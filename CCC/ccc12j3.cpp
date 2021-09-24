#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

char grid[3][3] = {
    {'*', 'x', '*'},
    {' ', 'x', 'x'},
    {'*', ' ', '*'}
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < 3 * n; ++i){
        for (int j = 0; j < 3 * n; ++j){
            cout << grid[i / n][j / n];
        }
        cout << '\n';
    }
}
