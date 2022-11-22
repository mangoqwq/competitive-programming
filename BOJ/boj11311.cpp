#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int a, b, d; cin >> a >> b >> d;
        if (b > a) swap(a, b);
        int g = gcd(a, b);
        cout << (d % g == 0 ? "Yes" : "No") << '\n';
    }
}
