#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 201;

int n;
char s[MN][MN], t[MN][MN], tmp[MN][MN];

void rotate(){
    for (int j = 1; j <= n; ++j){
        for (int i = 1; i <= n; ++i){
            tmp[i][j] = t[j][n - i + 1];
        }
    }
    swap(t, tmp);
}

set<pair<int, int>> get(char a[MN][MN]){
    set<pair<int, int>> ret;
    int sx = -1, sy = -1;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            if (a[i][j] == '.') continue;
            if (sx == -1) sx = i, sy = j;
            ret.insert({i - sx, j - sy});
        }
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> s[i][j];
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> t[i][j];
        }
    }
    bool ans = 0;
    for (int i = 1; i <= 4; ++i){
        ans |= get(s) == get(t);
        rotate();
        // for (int i = 1; i <= n; ++i){
        //     for (int j = 1; j <= n; ++j){
        //         cout << t[i][j];
        //     }
        //     cout << '\n';
        // }
    }
    cout << (ans ? "Yes" : "No") << '\n';
}
