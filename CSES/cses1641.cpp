#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5001;
ll a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X; cin >> N >> X;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    map<int, int> mp;
    for (int i = 2; i <= N; ++i){
        mp[a[i - 1]] = i - 1;
        for (int j = i + 1; j <= N; ++j){
            if (mp.count(X - a[i] - a[j])){
                cout << mp[X - a[i] - a[j]] << " " << i << " " << j << '\n';
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
