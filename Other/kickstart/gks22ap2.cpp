#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

void solve(){
    string N; cin >> N;
    ll tot = 0;
    for (char c : N) tot += c - '0';
    ll ch = 9 - tot % 9;
    if (ch == 9){
        cout << N[0] << 0 << N.substr(1) << '\n';
    }
    else{
        for (int i = 0; i < N.size(); ++i){
            if (ch < N[i] - '0'){
                cout << N.substr(0, i);
                cout << ch;
                cout << N.substr(i);
                cout << '\n';
                return;
            }
        }
        cout << N << ch << '\n';
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 1; i <= T; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }    
}
