#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int ord[26];

bool cmp(string a, string b){
    for (int i = 0; ; ++i){
        if (i == a.size() && i == b.size()) return 0;
        if (i == a.size()) return 1;
        if (i == b.size()) return 0;
        if (a[i] != b[i]) return ord[a[i] - 'a'] < ord[b[i] - 'a'];
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= 26; ++i){
        char c; cin >> c;
        ord[c - 'a'] = i;
    }
    int n; cin >> n;
    vector<string> vec(n);
    for (auto &s : vec) cin >> s;
    sort(vec.begin(), vec.end(), cmp);
    for (auto s : vec) cout << s << '\n';
}
