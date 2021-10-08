#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

set<string> s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i){
        string str; cin >> str;
        reverse(str.begin(), str.end());
        s.insert(str);
        reverse(str.begin(), str.end());
        if (s.find(str) != s.end()){
            cout << str.size() << " " << str[str.size() / 2] << '\n';
        }
    }
}
