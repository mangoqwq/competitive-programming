#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

vector<int> ans = {
    0,
    10001,
    10101,
    10201,
    11011,
    11111,
    11211,
    12021,
    10301,
    13031
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cerr << accumulate(ans.begin(), ans.end(), 0) << '\n';
    for (int x : ans) cout << x << '\n';
}
