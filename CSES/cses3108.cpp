#include <bits/stdc++.h>
#include <cinttypes>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N, K; cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  ranges::sort(a);
  struct State {
    int idx, pos, lim; ll tot;
    bool operator<(const State &other) const {
      return tot > other.tot;
    };
  };
  priority_queue<State> pq;
  ll sum = 0;
  for (int m = 0; m <= N; ++m) {
    pq.emplace(m, m, N, sum);
    if (m < N) sum += a[m];
  }

  vector<ll> ans;
  while ((int)ans.size() < K) {
    auto [idx, pos, lim, tot] = pq.top(); pq.pop();
    debug(idx, pos, lim, tot);
    ans.push_back(tot);
    if (idx == 0) continue;
    if (pos != lim) {
      pq.emplace(idx, pos + 1, lim, tot + a[pos] - a[pos - 1]);
    }
    if (idx != pos && idx > 1) {
      pq.emplace(idx - 1, idx, pos - 1, tot + a[idx - 1] - a[idx - 2]);
    }
  }
  for (int i = 0; i < K; ++i) {
    cout << ans[i] << (i == K - 1 ? '\n' : ' ');
  }
}
