#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    function<int(int, int)> fpow = [&](int b, int e){
        int ret = 1;
        while (e){
            if (1 & e) ret = ret * b;
            b = b * b; e >>= 1;
        }
        return ret;
    };

    int T; cin >> T;
    while (T--){
        int L, R; cin >> L >> R;
        string l = to_string(L), r = to_string(R);
        if (l.size() == r.size()){
            cout << R - L + 1 << '\n';
        }
        else{
            int tmp = fpow(10, r.size() - 1);
            if (R >= 2 * tmp){
                cout << R - tmp + 1 << '\n';
            }
            else{
                int tmp2 = fpow(10, r.size() - 2) + 1;
                cout << (1 + R - max({L, tmp2, R - tmp + 1, R / 10 + 1})) << '\n';
            }
        }
    }
}
