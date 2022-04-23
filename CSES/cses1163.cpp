#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int X, N; cin >> X >> N;
    set<int> lights; map<int, int> ans;
    lights.insert(0);
    lights.insert(X);
    ans[X]++;
    for (int i = 1; i <= N; ++i){
        int p; cin >> p;
        int r = *(lights.upper_bound(p));
        int l = *(--lights.upper_bound(p));
        ans[r - l]--;
        if (ans[r - l] == 0) ans.erase(r - l);
        ans[p - l]++;
        ans[r - p]++;
        lights.insert(p);
        cout << (--ans.end())->first << " ";
    }
    cout << '\n';
}
