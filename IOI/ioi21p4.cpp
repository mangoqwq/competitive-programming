#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

map<string, int> id = {{"AT", 0}, {"AC", 1}, {"TA", 2}, {"TC", 3}, {"CA", 4}, {"CT", 5}};
int cnt[MN][6];

void init(string s, string t){
    s = " " + s; t = " " + t;
    for (int i = 1; i < s.size(); ++i){
        for (int j = 0; j < 6; ++j) cnt[i][j] = cnt[i - 1][j];
        if (s[i] != t[i]) cnt[i][id[string(1, s[i]) + t[i]]]++;
    }
}

int get_distance(int l, int r){
    l++, r++;
    int at = cnt[r][0] - cnt[l - 1][0];
    int ac = cnt[r][1] - cnt[l - 1][1];
    int ta = cnt[r][2] - cnt[l - 1][2];
    int tc = cnt[r][3] - cnt[l - 1][3];
    int ca = cnt[r][4] - cnt[l - 1][4];
    int ct = cnt[r][5] - cnt[l - 1][5];
    if (at + ac != ta + ca) return -1;
    if (ta + tc != at + ct) return -1;
    if (ca + ct != ac + tc) return -1;
    int ans = min(at, ta) + min(ac, ca) + min(tc, ct);
    at = max(at, ta) - min(at, ta);
    ans += 2 * at;
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    init("ATACAT", "ACTATA");
    cout << get_distance(1, 3) << '\n';
    cout << get_distance(4, 5) << '\n';
    cout << get_distance(3, 5) << '\n';
}
