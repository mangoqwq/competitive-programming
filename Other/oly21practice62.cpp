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
    for (int i = 1; i <= n; ++i){
        string s; cin >> s;
        ans = max(ans, accumulate(s.begin(), s.end(), 0) - '0' * (int)s.size());
    }
    cout << ans << '\n';
}
