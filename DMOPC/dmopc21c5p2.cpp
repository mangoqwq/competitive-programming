#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    if (N == 1) cout << "1" << '\n';
    else if (N == 2) cout << -1 << '\n';
    else if (N >= 3){
        cout << 1 << " " << 3 << " " << 2 << (N == 3 ? '\n' : ' ');
        for (int i = 4; i <= N; ++i){
            cout << i << (i == N ? '\n' : ' ');
        }
    }
}
