#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, T; cin >> N >> T;
    while (T--){
        if (N % 2 == 1){
            cout << 1 << '\n';
            cout << ((N + 1) / 2) << " " << ((N + 1) / 2) << '\n';
        }
        else{
            cout << 2 << '\n';
        }
        cout.flush();
        while (true){
            int x, y; cin >> x >> y;
            if (x == 0 && y == 0) break;
            cout << N - x + 1 << " " << N - y + 1 << '\n';
            cout.flush();
        }
    }
}
