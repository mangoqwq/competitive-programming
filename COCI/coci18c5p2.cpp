#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

map<int, int> mp;
int a[MN], b[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= N; ++i) cin >> b[i];
    int ans = 0;
    for (int i = 1; i <= N; ++i){
        mp[a[i] - b[i]]++;
        ans = max(ans, mp[a[i] - b[i]]);
    }
    cout << ans << '\n';
}
