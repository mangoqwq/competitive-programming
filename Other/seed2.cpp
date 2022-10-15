#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int lo = 1, hi = 2e9;
    while (lo <= hi){
        int mid = (1LL + lo + hi) >> 1;
        cout << mid << '\n';
        cout.flush();
        string s; cin >> s;
        if (s == "SINKS") lo = mid + 1;
        else if (s == "FLOATS") hi = mid - 1;
        else return 0;
    }
}
