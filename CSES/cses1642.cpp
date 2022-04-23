#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1001;
ll a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X; cin >> N >> X;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    map<int, pair<int, int>> mp;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j < i - 1; ++j){
            mp[a[i - 1] + a[j]] = {j, i - 1};
        }
        for (int j = i + 1; j <= N; ++j){
            int rem = X - a[i] - a[j];
            if (mp.count(rem)){
                cout << mp[rem].first << " " << mp[rem].second << " " << i << " " << j << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
