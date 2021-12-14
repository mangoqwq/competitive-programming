#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e4 + 1;

int cnt[MN][26];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int N = s.size(); s = " " + s;
    for (int i = 1; i <= N; ++i){
        for (int j = 0; j < 26; ++j){
            cnt[i][j] += cnt[i - 1][j];
        }
        cnt[i][s[i] - 'a']++;
    }
    int Q; cin >> Q;
    while (Q--){
        bool same = 1;
        int a, b, c, d; cin >> a >> b >> c >> d;
        for (int i = 0; i < 26; ++i){
            same &= (cnt[b][i] - cnt[a - 1][i]) == (cnt[d][i] - cnt[c - 1][i]);
        }
        cout << (same ? "DA" : "NE") << '\n';
    }
}
