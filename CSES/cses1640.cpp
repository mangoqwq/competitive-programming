#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, x; cin >> N >> x;
    map<int, int> s;
    for (int i = 1; i <= N; ++i){
        int a; cin >> a;
        if (s.count(x - a)){
            cout << s[x - a] << " " << i << '\n';
            return 0;
        }
        s[a] = i;
    }
    cout << "IMPOSSIBLE" << '\n';
}
