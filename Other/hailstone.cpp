#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int ans = 0;
    while (n != 1){
        ans++;
        if (n % 2) n = n * 3 + 1;
        else n = n / 2;
    }
    cout << ans << '\n';
}
