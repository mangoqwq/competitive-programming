#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

void solve(){
    string a, b; cin >> a >> b;
    int i = 0, ans = 0;
    for (char c : a){
        while (true){
            if (i == b.size()){
                cout << "IMPOSSIBLE" << '\n';
                return;
            }
            if (b[i] == c){
                i++;
                break;
            }
            else i++, ans++;
        }
    }
    ans += b.size() - i;
    cout << ans << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }    
}
