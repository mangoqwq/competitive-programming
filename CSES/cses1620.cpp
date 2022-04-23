#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; ll K; cin >> N >> K;
    vector<int> k(N);
    for (int &x : k) cin >> x;
    ll lo = 1, hi = K * k[0], mid;
    while (lo < hi){
        mid = (lo + hi) >> 1;
        ll cur = 0;
        for (int x : k){
            cur += mid / x;
            if (cur >= K) break;
        }
        if (cur >= K) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
}
