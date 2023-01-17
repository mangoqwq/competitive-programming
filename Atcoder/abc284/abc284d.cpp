#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll Sqrt(ll N){
    ll lo = 1, hi = 3e9;
    while (lo < hi){
        ll mi = (lo + hi + 1) >> 1;
        if (mi * mi <= N) lo = mi;
        else hi = mi - 1;
    }
    return lo;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    const int L = 3e6;
    int T; cin >> T;
    while (T--){
        ll N; cin >> N;
        ll p, q;
        for (ll i = 2; i <= L; ++i){
            if (N % (i*i) == 0){
                p = i;
                q = N / (i*i);
                break;
            }
            if (N % i == 0){
                p = Sqrt(N / i);
                q = i;
                break;
            }
        }
        cout << p << " " << q << '\n';
    }
}
