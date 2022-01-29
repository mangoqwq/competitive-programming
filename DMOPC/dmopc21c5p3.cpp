#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

bool sieve[MN], win[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ms(sieve, 1);
    sieve[0] = sieve[1] = 0;
    vector<int> primes;
    for (ll i = 2; i < MN; ++i){
        if (!sieve[i]) continue;
        primes.push_back(i);
        for (ll j = i * i; j < MN; j += i) sieve[j] = 0;
    }
    for (int i = 1; i < MN; ++i){
        if (win[i]) continue;
        for (int x : primes){
            if (i + x < MN) win[i + x] = 1;
        }
    }
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        if (N == 1 || N == 2){
            cout << -1 << '\n';
            continue;
        }
        vector<int> ans(N + 1);
        iota(ans.begin() + 1, ans.begin() + 1 + N, 1);
        if (N == 11 || N == 36 || N == 311){
            swap(ans[N], ans[N - 2]);
            swap(ans[N], ans[N - 1]);
        }
        else if (!win[N]) swap(ans[N], ans[N - 1]);
        for (int i = 1; i <= N; ++i){
            cout << ans[i] << (i == N ? '\n' : ' ');
        }
    }
}
