#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    ll mn = 1, mx = 1e18;
    ll cur = 0;
    for (int i = 1; i <= N - 1; ++i){
        int x; cin >> x;
        cur = x - cur;
        if (i % 2){
            mx = min(mx, cur - 1);
        }
        else{
            mn = max(mn, -(cur - 1));
        }
    }
    cout << max(mx - mn + 1, 0LL) << '\n';
}
