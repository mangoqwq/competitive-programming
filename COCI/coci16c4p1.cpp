#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    ll tot = 0;
    while (N--){
        map<char, int> m;
        string s; cin >> s;
        for (char c : s) m[c]++;
        tot += m['A'] * 4 + m['K'] * 3 + m['Q'] * 2 + m['J'] * 1;
    }
    cout << tot << '\n';
}
