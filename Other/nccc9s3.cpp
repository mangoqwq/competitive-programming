#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    string s; cin >> s;
    s = "U" + s;
    int ans = 0;
    for (int i = 1; i <= 2 * N; ++i){
        if (s[i] == 'U' && s[i - 1] == 'U'){
            ans++;
        }
    }
    cout << ans << '\n';
}
