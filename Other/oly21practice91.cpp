#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; getline(cin, s);
    int cnt = 0;
    for (char c : s){
        if (c >= 'a' && c <= 'z') cnt++;
        if (c >= 'A' && c <= 'Z') cnt--;
    }
    cout << (cnt == 0 ? "YES" : "NO") << '\n';
}
