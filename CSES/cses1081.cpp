#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> cnt(1e6 + 1);
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        cnt[x]++;
    }
    for (int i = 1e6; i >= 1; --i){
        int cur = 0;
        for (int j = i; j <= 1e6; j += i){
            cur += cnt[j];
            if (cur >= 2){
                cout << i << '\n';
                return 0;
            }
        }
    }
}
