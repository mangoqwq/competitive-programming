#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int cnt[26][26];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        string s; cin >> s;
        cnt[s[0] - 'A'][s.back() - 'A']++;
    }
    ll ans = 0, cur;
    for (int a = 0; a < 26; ++a){
        for (int b = 0; b < 26; ++b){
            for (int c = 0; c < 26; ++c){
                for (int d = 0; d < 26; ++d){
                    cur = 1;
                    cur *= cnt[a][b]; cnt[a][b]--;
                    cur *= cnt[a][c]; cnt[a][c]--;
                    cur *= cnt[b][d]; cnt[b][d]--;
                    cur *= cnt[c][d]; cnt[c][d]--;
                    ans += cur;
                    cnt[a][b]++;
                    cnt[a][c]++;
                    cnt[b][d]++;
                    cnt[c][d]++;
                }
            }
        }
    }
    cout << ans << '\n';
}
