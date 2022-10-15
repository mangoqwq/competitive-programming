#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e4 + 1;

bool good(int msk){
    // check 5
    if ((1 & (msk >> 1)) == (1 & (msk >> 5)) &&
        (1 & (msk >> 2)) == (1 & (msk >> 4))) return 0;
    // check 6
    if ((1 & (msk >> 0)) == (1 & (msk >> 5)) &&
        (1 & (msk >> 1)) == (1 & (msk >> 4)) &&
        (1 & (msk >> 2)) == (1 & (msk >> 3))) return 0;
    return 1;
}

bool can[MN][(1 << 5)];

void solve(){
    ms(can, 0);
    int N; cin >> N;
    string s; cin >> s; s = " " + s;
    if (N <= 4){
        cout << "POSSIBLE" << '\n';
        return;
    }
    for (int i = 0; i < (1 << 5); ++i){
        int msk = i;
        if ((1 & (msk >> 0)) == (1 & (msk >> 4)) &&
            (1 & (msk >> 1)) == (1 & (msk >> 3))) continue;
        can[5][i] = 1;
        for (int j = 0; j < 5; ++j){
            if (s[j + 1] != '?' && (s[j + 1] - '0' != (1 & (i >> j)))){
                can[5][i] = 0;
            }
        }
        // if (can[5][i]) cout << bitset<5>(i).to_string() << '\n';
    }
    for (int i = 6; i <= N; ++i){
        bool zero = (s[i] == '0') || (s[i] == '?');
        bool one = (s[i] == '1') || (s[i] == '?');
        for (int lst = 0; lst < (1 << 5); ++lst){
            if (!can[i - 1][lst]) continue;
            if (zero){
                int msk = lst;
                if (good(msk)) can[i][msk >> 1] = 1;
            }
            if (one){
                int msk = lst + (1 << 5);
                if (good(msk)) can[i][msk >> 1] = 1;
            }
        }
    }
    cout << (*max_element(can[N], can[N] + (1 << 5)) ? "POSSIBLE" : "IMPOSSIBLE") << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }    
}
