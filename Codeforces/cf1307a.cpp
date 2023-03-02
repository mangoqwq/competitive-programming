#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, D; cin >> N >> D;
        int ans = 0;
        cin >> ans;
        for (int i = 1; i < N; ++i){
            int x; cin >> x;
            int num = min(D/i, x);
            ans += num;
            D -= i * num;
        }
        cout << ans << '\n';
    }
}
