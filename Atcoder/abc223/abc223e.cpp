#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 4;

bool ans;
ll a[MN];
void solve(ll x, ll y, int i){
    if (x < 0 || y < 0) return;
    if (i == 4){
        ans = 1;
    }
    else{
        if (!x || !y) return;
        solve(x - ((a[i] + y - 1) / y), y, i + 1);
        solve(x, y - ((a[i] + x - 1) / x), i + 1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int X, Y; cin >> X >> Y;
    for (int i = 1; i <= 3; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + 3);
    do{
        solve(X, Y, 1);
    } while(next_permutation(a + 1, a + 1 + 3));
    cout << (ans ? "Yes" : "No") << '\n';
}
