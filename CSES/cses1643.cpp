#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;
ll ans[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> ans[i];
        ans[i] = max(ans[i], ans[i - 1] + ans[i]);
    }
    cout << *max_element(ans + 1, ans + 1 + N) << '\n';
}
