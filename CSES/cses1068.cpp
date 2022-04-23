#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N; cin >> N;
    vector<ll> ans = {N};
    while (N != 1){
        if (N % 2 == 1) N = N * 3 + 1;
        else N = N / 2;
        ans.push_back(N);
    }
    for (ll x : ans){
        cout << x << " ";
    }
    cout << '\n';
}
