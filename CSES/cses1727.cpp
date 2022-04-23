#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    double tot = 0;
    for (int i = 1; i <= K; ++i){
        tot += i * (pow(i, N) - pow(i - 1, N));
    }
    tot /= pow(K, N);
    cout << fixed << setprecision(6) << tot << '\n';
}
