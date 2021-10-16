#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 505;

ll p[MN];
int mp[26];
int cnt[MN];
char g[MN][MN];
int fpsa[MN], rpsa[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            cin >> g[i][j];
        }
    }
    p[0] = 1;
    for (int i = 1; i < 26; ++i) p[i] = p[i - 1] * 503;
    bool can = 0;
    for (int i = 1; i <= N; ++i){
        for (int j = i + 1; j <= N; ++j){
            ms(fpsa, 0); ms(rpsa, 0);
            for (int k = 1; k <= N; ++k){
                fpsa[k] = fpsa[k - 1] + (g[i][k] == g[j][k]);
            }
            for (int k = N; k >= 1; --k){
                rpsa[k] = rpsa[k + 1] + (g[i][k] == g[j][k]);
            }
            ll hsh1 = 0, hsh2 = 0;
            for (int k = 1; k <= N; ++k){
                hsh1 += p[g[i][k] - 'a'];
                hsh2 += p[g[j][k] - 'a'];
                if (hsh1 == hsh2) cnt[k] = K;
                if (k >= K){
                    hsh1 -= p[g[i][k - K + 1] - 'a'];
                    hsh2 -= p[g[j][k - K + 1] - 'a'];
                }
            }
            for (int k = K; k <= N; ++k){
                if (fpsa[k - K] + cnt[k] + rpsa[k + 1] == N) can = 1;
            }
        }
    }
    cout << (can ? "DA" : "NE") << '\n';
}
