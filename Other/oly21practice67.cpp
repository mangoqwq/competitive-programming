#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int n;
string s;
int check(int sz){
    for (int i = 0; i < n; ++i){
        if (s[i] != s[i % sz]) return inf;
    }
    return sz;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        cin >> s;
        n = s.size();
        int ans = n;
        for (int i = 1; i * i <= n; ++i){
            if (n % i == 0){
                ans = min(ans, check(i));
                ans = min(ans, check(n / i));
            }
        }
        cout << n / ans << '\n';
    }
}
