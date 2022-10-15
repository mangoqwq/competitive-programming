#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, A, B; cin >> N >> A >> B;
    int ta = 0, tb = 0;
    for (int i = 1; i <= N; ++i){
        int X, Y; cin >> X >> Y;
        if (X >= A) ta++;
        if (Y >= B) tb++;
    }
    if (ta == tb) cout << "Tie!" << '\n';
    else cout << (ta < tb ? "Andrew wins!" : "Tommy wins!") << '\n';
}
