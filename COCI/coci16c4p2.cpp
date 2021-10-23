#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

string a[5] = {"", " ***ABCDE", " FGHIJKLM", " NOPQRSTU", " VWXYZ***"};
string arr[51];
bool want[26];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) cin >> arr[i];
    string s; cin >> s;
    for (int i = 1; i <= N; ++i){
        if (arr[i].size() <= s.size()) continue;
        if (arr[i].substr(0, s.size()) == s){
            want[arr[i][s.size()] - 'A'] = 1;
        }
    }
    for (int i = 1; i <= 4; ++i){
        for (int j = 1; j <= 8; ++j){
            if (a[i][j] == '*') cout << "*";
            else if (want[a[i][j] - 'A']) cout << a[i][j];
            else cout << "*";
        }
        cout << '\n';
    }
}
