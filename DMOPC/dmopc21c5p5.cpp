#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 100;
int N; bool prime[MN];
mt19937 gen;
int randint(int l, int r){ return gen() % (r - l + 1) + l; }
int val(int v){ return prime[v] ? v : 0; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N;
    ms(prime, 1);
    prime[0] = prime[1] = 0;
    for (int i = 2; i < N; ++i){
        if (prime[i]){
            for (int j = i * i; j < N; j += i) prime[j] = 0;
        }
    }
    vector<int> a(N); iota(a.begin(), a.end(), 1);
    vector<int> best = a;
    int ans = 0;
    for (int i = 1; i < N; ++i) ans += val(abs(a[i] - a[i - 1]));
    int last = ans;
    for (double t = 1e4; t >= 1e-4; t *= 0.999999){
        int num = randint(0, N * N - 1);
        int l = num / N, r = num % N;
        if (r < l) swap(l, r);

        int cur = last;
        if (l != 0) cur -= val(abs(a[l] - a[l - 1]));
        if (r != N - 1) cur -= val(abs(a[r] - a[r + 1]));
        if (l != 0) cur += val(abs(a[r] - a[l - 1]));
        if (r != N - 1) cur += val(abs(a[l] - a[r + 1]));

        if (cur > last || exp((double)(cur - last) / t) >= (double)gen() / gen.max()){
            reverse(a.begin() + l, a.begin() + r + 1);
            last = cur;
        }
        if (cur > ans){
            ans = cur;
            best = a;
        }
    }
    for (int i = 0; i < N; ++i){
        cout << best[i] << (i == N - 1 ? '\n' : ' ');
    }
}
