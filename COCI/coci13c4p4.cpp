#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

ll val[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N; N++;
    ll ans = 0;
    for (int i = 1; i <= N; ++i){
        int a; cin >> a;
        for (int j = 1; j * j <= a; ++j){
            if (a % j == 0){
                val[j] = j - 1;
                val[a / j] = a / j - 1;
            }
        }
    }
    for (int i = 2; i < MN; ++i){
        if (!val[i]) continue;
        ans += val[i];
        for (int j = i + i; j < MN; j += i){
            if (val[j]) val[j] -= val[i];
        }
    }
    cout << ans << '\n';
}
