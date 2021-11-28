#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5001;

int cnt[3];
int psa[MN][3];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    string bank; cin >> bank;
    for (char c : bank) cnt[c - 'a']++;
    string s; cin >> s;
    for (int i = N - 1; i >= 0; --i){
        for (int j = 0; j < 3; ++j) psa[i][j] = psa[i + 1][j];
        psa[i][s[i] - 'a']++;
    }
    for (int i = 0; i < N; ++i){
        for (char c = 'a'; c <= 'c'; ++c){
            if (c == s[i]) continue;
            if (!cnt[c - 'a']) continue;
            cnt[c - 'a']--;
            bool can = 1;
            for (int j = 0; j < 3; ++j){
                can &= (psa[i + 1][j] + cnt[j]) <= N - i - 1;
            }
            if (can){
                cout << c;
                break;
            }
            else cnt[c - 'a']++;
        }
    }
    cout << '\n';
}
