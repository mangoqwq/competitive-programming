#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 500, L = 17;
const int seed = 131;

map<ll, ll> cnt;
char c[MN][MN];
int hsh[MN][MN][8][L + 1];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int pw[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, K; cin >> N >> M >> K; K = min(K, N * M);
    pw[0] = seed;
    for (int i = 1; i <= L; ++i) pw[i] = 1LL * pw[i - 1] * pw[i - 1] % mod;
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            cin >> c[i][j];
            for (int k = 0; k < 8; ++k){
                hsh[i][j][k][0] = c[i][j];
            }
        }
    }
    for (int l = 1; l <= L; ++l){
        for (int i = 0; i < N; ++i){
            for (int j = 0; j < M; ++j){
                for (int k = 0; k < 8; ++k){
                    int x = ((i + (1LL << (l - 1)) * dx[k]) % N + N) % N;
                    int y = ((j + (1LL << (l - 1)) * dy[k]) % M + M) % M;
                    hsh[i][j][k][l] = (1LL * hsh[i][j][k][l - 1] * pw[l - 1] + hsh[x][y][k][l - 1]) % mod;
                }
            }
        }
    }
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < M; ++j){
            for (int k = 0; k < 8; ++k){
                ll cur = 0;
                int x = i, y = j;
                for (int l = 0; l <= L; ++l){
                    if (!(K & (1LL << l))) continue;
                    cur = cur * pw[l] + hsh[x][y][k][l];
                    x = ((x + (1LL << (l)) * dx[k]) % N + N) % N;
                    y = ((y + (1LL << (l)) * dy[k]) % M + M) % M;
                }
                cnt[cur]++;
            }
        }
    }

    ll denom = 1LL * N * M * 8 * N * M * 8;
    ll num = 0;
    for (auto [a, b] : cnt) num += b * b;
    ll g = gcd(denom, num);
    denom /= g, num /= g;
    cout << num << "/" << denom << '\n';
}
