#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) [&]() {
    ll N, M, K; cin >> N >> M >> K;
    ll mN = 2 * (N - 1);
    ll mM = 2 * (M - 1);
    ll x = min(K % mN, mN - (K % mN));
    ll y = min(K % mM, mM - (K % mM));
    ll bN = K / (N - 1);
    ll bM = K / (M - 1);
    ll bNM = K / lcm(N - 1, M - 1);
    ll b = bN + bM - bNM;
    cout << x + 1 << " " << y + 1 << " " << b << '\n';
  }();
}
