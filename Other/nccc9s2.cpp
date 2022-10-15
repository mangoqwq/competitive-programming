#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> pos;
    for (int i = 0; i < 2 * N; ++i){
        char c; cin >> c;
        if (c == 'I') pos.push_back(i);
    }
    ll ans = 0;
    for (int i = 0; i < 2 * N; i += 2){
        ans += abs(pos[i / 2] - i);
    }
    cout << ans << '\n';
}
