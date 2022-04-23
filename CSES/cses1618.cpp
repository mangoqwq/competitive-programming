#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N; cin >> N;
    ll cnt2 = 0, cnt5 = 0;
    for (ll i = 2; i <= N; i *= 2){
        cnt2 += N / i;
    }
    for (ll i = 5; i <= N; i *= 5){
        cnt5 += N / i;
    }
    cout << min(cnt2, cnt5) << '\n';
}
