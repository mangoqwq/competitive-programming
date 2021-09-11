#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    ll duke = 0, alice = 0;
    for (int i = 1; i <= N; ++i){
        int a; cin >> a;
        if (a % 2 == 0) duke += a / 2;
        if (a % 2 == 1) alice += (a + 1) / 2;
    }
    if (duke > alice) cout << "Duke" << '\n';
    else cout << "Alice" << '\n';
}
