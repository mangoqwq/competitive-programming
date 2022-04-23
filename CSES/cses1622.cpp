#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    sort(s.begin(), s.end());
    vector<string> ans;
    do{
        ans.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << ans.size() << '\n';
    for (string s : ans) cout << s << '\n';
}
