#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int v; cin >> v;
    string s; cin >> s;
    int a = 0, b = 0;
    for (char c : s){
        a += c == 'A';
        b += c == 'B';
    }
    if (a > b) cout << "A" << '\n';
    else if (b > a) cout << "B" << '\n';
    else cout << "Tie" << '\n';
}
