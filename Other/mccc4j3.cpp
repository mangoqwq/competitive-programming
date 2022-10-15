#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> a(N + 1);
    int tot = 0;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        tot += a[i];
    }
    int cur = 0;
    for (int i = 1; i <= N; ++i){
        cur += a[i];
        if (cur == tot / 2){
            cout << i << '\n';
            return 0;
        }
    }
    cout << "Andrew is sad." << '\n';
}
