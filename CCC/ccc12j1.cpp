#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int l, s; cin >> l >> s;
    int x = s - l;
    if (1 <= x && x <= 20) cout << "You are speeding and your fine is $100." << '\n';
    else if (21 <= x && x <= 30) cout << "You are speeding and your fine is $270." << '\n';
    else if (31 <= x) cout << "You are speeding and your fine is $500." << '\n';
    else cout << "Congratulations, you are within the speed limit!" << '\n';
}
