#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    map<char, int> cnt;
    for (char c : s) cnt[c]++;
    int odds = 0; char odd = 0;
    for (auto [c, num] : cnt){
        if (num % 2){
            odds++;
            odd = c;
        }
    }
    if (odds >= 2){
        cout << "NO SOLUTION" << '\n';
    }
    else{
        string ans = "";
        for (auto [c, num] : cnt){
            for (int i = 1; i <= num / 2; ++i){
                ans += c;
            }
        }
        cout << ans;
        if (odd) cout << odd;
        reverse(ans.begin(), ans.end());
        cout << ans;
        cout << '\n';
    }
}
