#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

map<string, int> cnt;
bool gold(string a, string b){
    set<char> s;
    for (char c : a) s.insert(c);
    for (char c : b) s.insert(c);
    return s.size() == 3;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N; cin >> N;
    string t, r, b, l; cin >> t >> r >> b >> l;
    for (int i = 0; i < N; ++i){
        string s = ""; s += t[i]; s += b[i];
        cnt[s]++;
    }
    ll ans = 0;
    for (int i = 0; i < N; ++i){
        string cur = "";
        cur += l[i]; cur += r[i];
        for (auto [s, c] : cnt){
            if (gold(cur, s)) ans += c;
        }
    }
    cout << ans << '\n';
}
