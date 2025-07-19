#include <bits/stdc++.h>
 
using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;
 
int mex(set<int> s){
    for (int i = 0; ; ++i){
        if (!s.count(i)) return i;
    }
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    int MX = 1222;
    vector<int> grundy(MX + 1);
    grundy[0] = 0;
    grundy[1] = 0;
    grundy[2] = 1;
    for (int i = 2; i <= MX; ++i){
        set<int> cur;
        for (int j = 1; j < i; ++j){
            if (j * 2 != i){
                cur.insert(grundy[j] ^ grundy[i - j]);
            }
        }
        grundy[i] = mex(cur);
    }
    while (T--){
        int N; cin >> N;
        if (N > MX) cout << "first" << '\n';
        else cout << (grundy[N] ? "first" : "second") << '\n';
    }
}
