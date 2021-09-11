#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e3 + 1;

vector<int> ans;
int a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    for (int i = 1; i <= N; ++i){
        int x = max_element(a + 1, a + 1 + N) - a;
        a[x] = -1;
        int idx = 1;
        for (int j = 1; j < x; ++j) if (a[j] != -1) idx++;
        ans.push_back(idx);
        if (idx != 1) ans.push_back(-(idx - 1));
    }
    ans.push_back(-N);
    cout << ans.size() << '\n';
    for (int x : ans) cout << x << '\n';
}
