#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

map<char, int> mp = {{'b', 0}, {'r', 1}, {'u', 2}, {'c', 3}, {'e', 4}};
vector<int> p[121];
int inv[121], pos[5];
vector<int> v[5];

int main(){
    cin.tie(0)->sync_with_stdio(0);

    vector<int> permu = {0, 1, 2, 3, 4};
    for (int i = 1; i <= 120; ++i){
        p[i] = permu;
        for (int j = 0; j < 5; ++j){
            for (int k = j + 1; k < 5; ++k){
                inv[i] += permu[j] > permu[k];
            }
        }
        next_permutation(permu.begin(), permu.end());
    }

    int T; cin >> T;
    while (T--){
        string s; cin >> s;
        for (int i = 0; i < 5; ++i) v[i].clear();
        for (int i = 0; i < 5; ++i) v[i].push_back(-inf);
        for (int i = 0; i < s.size(); ++i){
            char &c = s[i];
            if (mp.count(c)){
                c = mp[c];
                v[c].push_back(i);
            }
            else c = 5;
        }
        for (int i = 0; i < 5; ++i) v[i].push_back(inf);

        ll ans = inf;
        for (int i = 0; i < s.size(); ++i){
            for (int idx = 1; idx <= 120; ++idx){
                if (s[i] != p[idx][2]) continue;

                pos[2] = i;

                pos[1] = *(upper_bound(v[p[idx][1]].begin(), v[p[idx][1]].end(), pos[2]) - 1);
                pos[0] = *(upper_bound(v[p[idx][0]].begin(), v[p[idx][0]].end(), pos[1]) - 1);

                pos[3] = *(lower_bound(v[p[idx][3]].begin(), v[p[idx][3]].end(), pos[2]));
                pos[4] = *(lower_bound(v[p[idx][4]].begin(), v[p[idx][4]].end(), pos[3]));

                if (pos[4] == inf || pos[0] == -inf) continue;
                ll cur = inv[idx];
                cur += abs((pos[2] - 1) - pos[1]) + abs((pos[2] - 2) - pos[0]);
                cur += abs((pos[2] + 1) - pos[3]) + abs((pos[2] + 2) - pos[4]);
                ans = min(ans, cur);
            }
        }
        cout << ans << '\n';
    }
}
