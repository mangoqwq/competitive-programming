#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

set<char> vowels = {'A', 'E', 'I', 'O', 'U'};
int cost(char a, char b){
    if (a == b) return 0;
    return (vowels.count(a) == vowels.count(b)) + 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("txt.in", "r", stdin);
    freopen("txt.out", "w", stdout);
    int T; cin >> T;
    for (int _ = 1; _ <= T; ++_){
        cout << "Case #" << _ << ": ";
        string s; cin >> s;
        int ans = inf, cur;
        for (char c = 'A'; c <= 'Z'; ++c){
            cur = 0;
            for (char x : s) cur += cost(x, c);
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }
}
