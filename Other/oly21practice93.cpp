#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, L; cin >> N >> L;
    vector<string> v;
    for (int i = 1; i <= N; ++i){
        string s; cin >> s;
        string t = s;
        reverse(t.begin(), t.end());
        v.push_back(min(s, t));
    }
    sort(v.begin(), v.end());
    for (string s : v) cout << s;
    cout << '\n';
}
