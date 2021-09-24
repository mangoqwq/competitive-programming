#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int x, y; cin >> x >> y;
    for (int i = x; i <= y; i += 60){
        cout << "All positions change in year " << i << '\n';
    }
}
