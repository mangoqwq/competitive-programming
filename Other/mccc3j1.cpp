#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int i, j; cin >> i >> j;
    if (abs(i * i - N) < abs(j * j - N)) cout << 1 << '\n';
    else cout << 2 << '\n';
}
