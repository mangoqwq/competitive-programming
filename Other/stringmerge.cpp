#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int cnt[3];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        ms(cnt, 0);
        string s; cin >> s;
        int n = s.size();
        for (char c : s) cnt[c - 'a']++;
        int zero = 0, can = 0;
        for (int i = 0; i < 3; ++i){
            if ((n - cnt[i]) % 2) can = 1;
            if (cnt[i] == 0) zero++;
        }
        if (zero == 2) cout << *max_element(cnt, cnt + 3) << '\n';
        else if (can) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
}
