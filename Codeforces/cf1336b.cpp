#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        using vi = vector<ll>;
        int N[3];
        cin >> N[0] >> N[1] >> N[2];
        vi a[3];
        for (int i = 0; i < 3; ++i){
            a[i].resize(N[i]);
            for (int j = 0; j < N[i]; ++j){
                cin >> a[i][j];
            }
            sort(a[i].begin(), a[i].end());
        }
        ll ans = 9e18;

        auto sq = [&](ll x) -> ll {
            return x * x;
        };

        auto solve = [&](vi a, vi b, vi c) -> void {
            for (int i = 0; i < a.size(); ++i){
                if (a[i] < c[0]) continue;
                int k = (--upper_bound(c.begin(), c.end(), a[i])) - c.begin();
                auto it = upper_bound(b.begin(), b.end(), (a[i] + c[k]) / 2);
                if (it != b.end()){
                    int j = it - b.begin();
                    ans = min(ans, sq(a[i] - b[j]) + sq(b[j] - c[k]) + sq(c[k] - a[i]));
                }
                if (it != b.begin()){
                    int j = (--it) - b.begin();
                    ans = min(ans, sq(a[i] - b[j]) + sq(b[j] - c[k]) + sq(c[k] - a[i]));
                }
            }
        };

        vector<int> ord = {0, 1, 2};
        do{
            solve(a[ord[0]], a[ord[1]], a[ord[2]]);
        } while (next_permutation(ord.begin(), ord.end()));
        cout << ans << '\n';
    }    
}
