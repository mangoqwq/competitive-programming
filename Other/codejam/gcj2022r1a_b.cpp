#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

void solve(){
    int N; cin >> N;
    ll tot = 0;
    vector<int> v;
    for (int i = 0; i <= 69; ++i){
        cout << (int)(1e9 - i) << " ";
        tot += (int)(1e9 - i);
        v.push_back(1e9 - i);
    }
    for (int i = 0; i <= 29; ++i){
        cout << (1 << i) << " ";
        tot += (1 << i);
        v.push_back((1 << i));
    }
    cout << '\n';
    cout.flush();
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        tot += x;
        v.push_back(x);
    }
    sort(v.begin(), v.end(), greater<int>());
    tot /= 2;
    for (int x : v){
        if (x <= tot){
            tot -= x;
            cout << x << " ";
        }
    }
    cout << '\n';
    cout.flush();
    
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
