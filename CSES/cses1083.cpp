#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int tot = 0;
    for (int i = 1; i <= N; ++i) tot ^= i;
    for (int i = 1; i <= N - 1; ++i){
        int x; cin >> x;
        tot ^= x;
    }
    cout << tot << '\n';
}
