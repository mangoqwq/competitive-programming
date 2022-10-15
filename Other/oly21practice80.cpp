#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N; cin >> N;
    vector<ll> ans;
    for (ll i = 1; i * i <= N; ++i){
        if (N % i == 0){
            ans.push_back(i);
            if (i * i != N) ans.push_back(N / i);
        }
    }
    sort(ans.begin(), ans.end());
    for (ll x : ans) cout << x << '\n';
}
