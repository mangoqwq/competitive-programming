#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

bool need[16];
bool valid[(1 << 16)];
bool other[(1 << 16)];

bool adj(int i, int j){
    int r1 = i / 4;
    int r2 = j / 4;
    int c1 = i % 4;
    int c2 = j % 4;
    return (abs(r2 - r1) + abs(c2 - c1)) == 1;
}

bool border(int i){
    int r = i / 4;
    int c = i % 4;
    return r == 0 || r == 3 || c == 0 || c == 3;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 16; ++i) cin >> need[i];
    for (int i = 0; i < 16; ++i) valid[1 << i] = 1;
    for (int i = 0; i < 16; ++i) if (border(i)) other[1 << i] = 1;
    other[0] = 1;
    for (int mask = 0; mask < (1 << 16); ++mask){
        for (int i = 0; i < 16; ++i){
            if (1 & (mask >> i)) continue;
            if (valid[mask]){
                for (int j = 0; j < 16; ++j){
                    if (!(1 & (mask >> j))) continue;
                    if (adj(i, j)) valid[mask + (1 << i)] = 1;
                }
            }

            if (other[mask]){
                if (border(i)) other[mask + (1 << i)] = 1;
                for (int j = 0; j < 16; ++j){
                    if (!(1 & (mask >> j))) continue;
                    if (adj(i, j)) other[mask + (1 << i)] = 1;
                }
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << 16); ++mask){
        if (!valid[mask]) continue;
        bool good = other[(1 << 16) - 1 - mask];
        for (int i = 0; i < 16; ++i){
            if (need[i] && !(1 & (mask >> i))) good = 0;
        }
        ans += good;
    }
    cout << ans << '\n';
}
