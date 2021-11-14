#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e4 + 5;

char s[MN];
map<char, int> cost;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string str; cin >> str;
    int N = str.size();
    for (int i = 1; i <= N; ++i) s[i] = str[i - 1];
    string t; cin >> t;
    cin >> cost['A'];
    cin >> cost['C'];
    cin >> cost['G'];
    cin >> cost['T'];

    int ans = inf;
    for (int i = 1; i <= N; ++i){
        int cur = 0;
        int idx = i;
        for (char c : t){
            if (c == s[idx]) idx++;
            else cur += cost[c];
        }
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}
