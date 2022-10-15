#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e7 + 1;

bool skip[MN];
int nxt[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= (int)1e7; ++i){
        int tmp = 1;
        bool bad = 0;
        for (int j = 0; j <= 7; ++j){
            if ((i / tmp) % 10 == 7){
                bad = 1;
                break;
            }
            tmp *= 10;
        }
        if (!bad) continue;
        for (int j = i; j < MN; j += i){
            skip[j] = 1;
        }
    }
    int p = inf;
    for (int i = MN - 1; i >= 1; --i){
        nxt[i] = p;
        if (!skip[i]) p = i;
    }
    int T; cin >> T;
    while (T--){
        int x; cin >> x;
        if (skip[x]){
            cout << -1 << '\n';
        }
        else{
            cout << nxt[x] << '\n';
        }
    }
}
