#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        char c; cin >> c;
        if (c == 'x') m--;
        if (c == 'o') m++;
        m = max(m, 0);
    }
    cout << m << '\n';
}
