#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i += 2){
        for (int j = 1; j <= i; ++j) cout << "*";
        for (int j = 1; j <= 2 * (n - i); ++j) cout << " ";
        for (int j = 1; j <= i; ++j) cout << "*";
        cout << '\n';
    }
    for (int i = n - 2; i >= 1; i -= 2){
        for (int j = 1; j <= i; ++j) cout << "*";
        for (int j = 1; j <= 2 * (n - i); ++j) cout << " ";
        for (int j = 1; j <= i; ++j) cout << "*";
        cout << '\n';
    }
}
