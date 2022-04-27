#include <bits/stdc++.h>
#pragma GCC target("popcnt")

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<bitset<3000>> a(N);
    for (int i = 0; i < N; ++i){
        string s; cin >> s;
        a[i] = bitset<3000>(s);
    }
    ll ans = 0;
    for (int i = 0; i < N; ++i){
        for (int j = i + 1; j < N; ++j){
            ll cnt = (a[i] & a[j]).count();
            ans += (cnt) * (cnt - 1) / 2;
        }
    }
    cout << ans << '\n';
}
