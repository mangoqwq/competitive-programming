#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int a, b; cin >> a >> b;
        if ((a + b) % 3){
            cout << "NO" << '\n';
            continue;
        }
        int moves = (a + b) / 3;
        if (abs(a - b) > moves){
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
    }
}
