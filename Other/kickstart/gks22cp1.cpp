#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    int N; cin >> N;
    string s; cin >> s;
    bool upper = 0, lower = 0, digit = 0, special = 0;
    for (char c : s){
        if (c >= 'A' && c <= 'Z') upper = 1;
        if (c >= 'a' && c <= 'z') lower = 1;
        if (c >= '0' && c <= '9') digit = 1;
        if (c == '#' || c == '@' || c == '*' || c == '&') special = 1;
    }
    if (!upper) s += 'A';
    if (!lower) s += 'a';
    if (!digit) s += '0';
    if (!special) s += '#';
    while (s.size() < 7) s += '&';
    cout << s << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
