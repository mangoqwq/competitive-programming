#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 5;

int x[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int cur = 0;
    for (int i = 1; i <= N; ++i){
        cin >> x[i];
        cur += abs(x[i] - x[i - 1]);
    }
    cur += abs(x[N + 1] - x[N]);
    for (int i = 1; i <= N; ++i){
        int tmp = cur;
        tmp -= abs(x[i] - x[i - 1]);
        tmp -= abs(x[i + 1] - x[i]);
        tmp += abs(x[i + 1] - x[i - 1]);
        cout << tmp << '\n';
    }
}
