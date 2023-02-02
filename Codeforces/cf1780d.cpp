#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int bits; cin >> bits;
        int ans = 0;
        for (int i = 0; i < 30; ++i){
            cout << "- " << (1<<i) << '\n';
            cout.flush();
            int x; cin >> x;
            int add = (1 << (i+(x-bits+1)));
            int savi = (i+(x-bits+1));
            if (add-(1<<i)){
                cout << "- " << add-(1<<i) << '\n';
                cout.flush();
                cin >> x;
            }
            ans += add;
            bits = x;
            i = savi;
            if (!bits) break;
        }
        cout << "! " << ans << '\n';
        cout.flush();
    }
}
