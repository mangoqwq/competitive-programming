#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        int tot = 0;
        for (int i = 1; i <= N; ++i){
            int a; cin >> a;
            if (i % 2 == 0) tot ^= a;
        }
        cout << (tot == 0 ? "second" : "first") << '\n';
    }
}
