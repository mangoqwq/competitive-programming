#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, P; cin >> N >> P;
    vector<int> idx, val;
    int M = 0, lastans = 0;
    for (int i = 1; i <= N; ++i){
        char c; int x; cin >> c >> x;
        x ^= lastans;
        if (c == 'A'){
            M++;
            while (!val.empty() && val.back() < x){
                val.pop_back(); idx.pop_back();
            }
            val.push_back(x); idx.push_back(M);
        }
        else{
            int pos = lower_bound(idx.begin(), idx.end(), M - x + 1) - idx.begin();
            cout << (lastans = val[pos]) << '\n';
        }
    }
}
