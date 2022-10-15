#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int s; cin >> s;
    vector<int> a(n - 1);
    for (int &x : a) cin >> x;
    cout << (s > *max_element(a.begin(), a.end()) ? "YES" : "NO") << '\n';
}
