#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

set<int> in[7];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, p; cin >> n >> p;
    ll tot = 0;
    for (int i = 1; i <= n; ++i){
        int s, x; cin >> s >> x;
        while (!in[s].empty() && *(--in[s].end()) > x){
            in[s].erase(--in[s].end()); tot++;
        }
        if (in[s].empty() || *(--in[s].end()) != x) tot++, in[s].insert(x);
    }
    cout << tot << '\n';
}
