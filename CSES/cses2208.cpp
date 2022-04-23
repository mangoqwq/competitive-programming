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
        bool odd = 0;
        while (N--){
            int a; cin >> a;
            odd |= (a % 2 == 1);
        }
        cout << (odd ? "first" : "second") << '\n';
    }
}
