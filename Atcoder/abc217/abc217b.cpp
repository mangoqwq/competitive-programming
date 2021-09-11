#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    set<string> s = {"ABC", "ARC", "AGC", "AHC"};
    for (int i = 1; i <= 3; ++i){
        string x; cin >> x;
        s.erase(x);
    }
    cout << (*s.begin()) << '\n';
}
