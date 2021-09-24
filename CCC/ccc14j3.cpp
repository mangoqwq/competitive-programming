#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int a = 100, b = 100;
    while (n--){
        int x, y; cin >> x >> y;
        int lose = max(x, y);
        if (x > y) b -= lose;
        if (y > x) a -= lose;
    }
    cout << a << '\n' << b << '\n';
}
