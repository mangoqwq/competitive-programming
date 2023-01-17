#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        int ans = 0;
        for (int i = 0; i < N; ++i){
            int x; cin >> x;
            if (x % 2 == 1) ans++;
        }
        cout << ans << '\n';
    }
}
