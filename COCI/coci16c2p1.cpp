#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    string best;
    int most = -1, tot = 0;
    for (int i = 1; i <= N; ++i){
        string name; cin >> name;
        int k, m; cin >> k >> m;
        int cur = 0;
        while (m >= k){
            cur++; m -= k - 2;
        }
        tot += cur;
        if (cur > most) best = name, most = cur;
    }
    cout << tot << '\n' << best << '\n';
}
