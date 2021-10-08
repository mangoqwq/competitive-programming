#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s, t; cin >> s >> t;
    string ans = "";
    for (char c : s){
        ans += c;
        while (ans.size() >= t.size() && ans.substr(ans.size() - t.size()) == t){
            ans = ans.substr(0, ans.size() - t.size());
        }
    }
    if (ans == "") ans = "FRULA";
    cout << ans << '\n';
}
