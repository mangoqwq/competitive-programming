#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e6 + 15;

bool sieve[MN];
int can[MN];
vector<int> ans;

void gen(int s, int a, int b){
    if (a > b) swap(a, b);
    int c = 1;
    for (int i = 1; i <= a + b; ++i){
        ans.push_back(c);
        if (c > b) c -= b;
        else c += a;
    }
}

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
    for (int x : primes){
        if (x == 2) continue;
        x += 2;
        for (int j = x; j < MN; j += x) can[j] = x;
    }
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        ans.clear();
        if (N == 1){
            cout << 1 << '\n';
            continue;
        }
        if (N <= 3){
            cout << -1 << '\n';
            continue;
        }
        if (N == 4){
            cout << "3 1 4 2" << '\n';
            continue;
        }
        if (N == 5){
            cout << "1 3 5 2 4" << '\n';
            continue;
        }
        if (N == 6){
            cout << "2 4 6 1 3 5" << '\n';
            continue;
        }
        if (N == 7){
            cout << "2 4 6 1 3 5 7" << '\n';
            continue;
        }
        bool odd = 0;
        if (N % 2 == 1) N++, odd = 1;
        int idx = (--upper_bound(primes.begin(), primes.end(), N)) - primes.begin();
        for (int i = idx; i >= 0; --i){
            if (primes[i] == N - primes[i]) continue;
            if (sieve[N - primes[i]]){
                gen(1, primes[i], N - primes[i]);
                break;
            }
        }

        if (odd){
            for (int i = 1; i < N; ++i){
                cout << ans[i] - 1 << (i == N - 1 ? '\n' : ' ');
            }
        }
        else{
            for (int i = 0; i < N; ++i){
                cout << ans[i] << (i == N - 1 ? '\n' : ' ');
            }
        }
    }
}
