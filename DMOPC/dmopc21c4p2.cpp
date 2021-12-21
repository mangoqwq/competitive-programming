#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e6 + 1;

bool need[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        need[x] = 1;
    }
    int ans = 0;
    for (int i = 1; i < MN; ++i){
        if (need[i]){
            ans++;
            for (int j = i; j < MN; j += i){
                need[j] = 0;
            }
        }
    }
    cout << ans << '\n';
}
