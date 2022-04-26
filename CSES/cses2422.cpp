#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N; cin >> N;
    ll need = N * N / 2 + 1;
    ll lo = 1, hi = N * N;
    while (lo < hi){
        ll mid = (lo + hi) >> 1;
        ll cnt = 0;
        for (int i = 1; i <= N; ++i) cnt += min(N, mid / i);
        if (cnt < need) lo = mid + 1;
        else hi = mid;
    }
    cout << lo << '\n';
}
