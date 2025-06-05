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
  int N; cin >> N;
  vector<ll> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }

  const int P = 1 << N / 2;
  const int NP = 1 << ((N + 1) / 2);
  vector<ll> dp(P);
  dp[0] = 1;
  for (ll x : a) {
    auto nxt = dp;
    for (int i = 0; i < P; ++i) {
      nxt[(i + x) % P] += dp[i];
    }
    dp = nxt;
  }
  dp[0]--;

  int p = [&]() {
    for (int i = 0; i < P; ++i) {
      if (dp[i] > ((1LL << N) - 2 - i) / P + 1) return i;
    }
    assert(false);
  }();
  debug(p);

  const ll L = (1 << N / 2), R = (1 << (N + 1) / 2);
  vector<vector<pair<ll, ll>>> rig(P);
  for (int r_msk = 0; r_msk < R; ++r_msk) {
    ll tot = 0;
    for (int i = 0; i < (N + 1) / 2; ++i) {
      if (1 & (r_msk >> i)) tot += a[N / 2 + i];
    }
    rig[tot % P].emplace_back(r_msk, tot);
  }
  vector<ll> occ(NP);
  for (int l_msk = 0; l_msk < L; ++l_msk) {
    ll l_tot = 0;
    for (int i = 0; i < N / 2; ++i) {
      if (1 & (l_msk >> i)) l_tot += a[i];
    }
    ll r_want = (p - (l_tot % P) + P) % P;
    for (auto [r_msk, r_tot] : rig[r_want]) {
      ll tot = l_tot + r_tot;
      if (occ[tot / P]) {
        ll msk1 = occ[tot / P];
        ll msk2 = l_msk + L * r_msk;
        ll common = msk1 & msk2;
        msk1 -= common;
        msk2 -= common;
        auto print = [&](ll msk) {
          vector<int> elems;
          for (int i = 0; i < N; ++i) {
            if (1 & (msk >> i)) elems.push_back(i);
          }
          int k = elems.size();
          cout << k << '\n';
          for (int i = 0; i < k; ++i) {
            cout << a[elems[i]] << (i == k-1 ? '\n' : ' ');
          }
        };
        print(msk1);
        print(msk2);
        return 0;
      }
      occ[tot / P] = l_msk + L * r_msk;
    }
  }
}
