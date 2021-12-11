#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> v(N + 1);
    int sum = 0;
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        sum ^= x;
        v[i] = x;
    }
    for (int i = 1; i <= N; ++i){
        if (v[i] == sum){
            cout << "Win" << '\n';
            return 0;
        }
    }
    cout << (N % 2 == 0 ? "Lose" : "Win") << '\n';
}
