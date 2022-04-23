#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

map<char, int> mp = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
char ch[4] = {'A', 'C', 'G', 'T'};
vector<int> pos[4];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    for (int i = 0; i < s.length(); ++i){
        pos[mp[s[i]]].push_back(i);
    }
    int cur = -1;
    string ans = "";
    for (int i = 0; i < s.length(); ++i){
        char add; int mx = cur;
        for (int j = 0; j < 4; ++j){
            auto it = upper_bound(pos[j].begin(), pos[j].end(), cur);
            if (it == pos[j].end()){
                ans += ch[j];
                cout << ans << '\n';
                return 0;
            }
            if (*it > mx) add = ch[j], mx = *it;
        }
        ans += add;
        cur = mx;
    }
}
