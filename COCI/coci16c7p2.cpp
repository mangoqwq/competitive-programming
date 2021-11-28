#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N; cin >> N;
    vector<pair<ll, ll>> cand;
    for (ll i = 2; i * i <= N * 2; ++i){
        if (i % 2 == 0 && N * 2 % i) continue;
        if (i % 2 == 0 && N % i == 0) continue;
        if (i % 2 == 1 && N % i) continue;
        if (i % 2 == 0){
            cand.push_back({N / i - i / 2 + 1, N / i + i / 2});
        }
        else{
            cand.push_back({N / i - i / 2, N / i + i / 2});
        }
    }
    for (auto [l, r] : cand){
        if (l > 0){
            cout << l << " " << r << '\n';
        }
    }
}
