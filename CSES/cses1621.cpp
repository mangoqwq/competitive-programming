#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> a(N);
    for (auto &x : a) cin >> x;
    a.push_back(0);
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 1; i <= N; ++i){
        ans += a[i] != a[i - 1];
    }
    cout << ans << '\n';
}
