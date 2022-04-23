#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;
bitset<MN> can;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    can[0] = 1;
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        can |= (can << x);
    }
    cout << can.count() - 1 << '\n';
    for (int i = 1; i < MN; ++i){
        if (can[i]) cout << i << " ";
    }
    cout << '\n';
}
