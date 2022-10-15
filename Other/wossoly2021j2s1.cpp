#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    map<int, char> mp;
    for (int i = 1; i <= 10; ++i){
        char c; cin >> c;
        mp[i - 1] = c;
    }
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        cout << mp[x];
    }
    cout << '\n';
}
