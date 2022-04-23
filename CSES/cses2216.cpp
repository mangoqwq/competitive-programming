#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int pos[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        pos[x] = i;
    }
    int ans = 1;
    for (int i = 2; i <= N; ++i){
        if (pos[i] < pos[i - 1]) ans++;
    }
    cout << ans << '\n';
}
