#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    double w, h; cin >> w >> h;
    double bmi = w / (h * h);
    if (bmi > 25) cout << "Overweight" << '\n';
    else if (bmi >= 18.5) cout << "Normal weight" << '\n';
    else cout << "Underweight" << '\n';
}
