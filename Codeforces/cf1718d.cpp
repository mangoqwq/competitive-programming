#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
  while (T--) [](){
    int N, Q; cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i){
      cin >> a[i];
    }

    using pii = pair<ll, int>;
    vector<priority_queue<pii>> best(N+1);
    vector<vector<ll>> ans(N+1);
    auto fix = [&](int d){
      while (true){
        auto [ret, idx] = best[d].top();
        if (ans[d][idx] != ret) best[d].pop();
        else return;
      }
    };
    auto get_ans = [&](int d){
      fix(d);
      return best[d].top().first;
    };
    auto ins = [&](ll x, int i, int d){
      best[d].push({x, i});
    };

    vector<int> divisors;
    int n = N;
    for (int p = 2; p <= N; ++p){
      if (n % p) continue;
      int d = N / p;
      while (n % p == 0) n /= p;
      divisors.push_back(d);
      ans[d].resize(d);
      for (int i = 0; i < N; ++i){
        ans[d][i % d] += a[i] * d;
      }
      for (int i = 0; i < d; ++i){
        ins(ans[d][i], i, d);
      }
    }

    ll ret = 0;
    for (int d : divisors){
      ret = max(ret, get_ans(d));
    }
    cout << ret << '\n';

    int its = 0;
    while (Q--){
      int i, x; cin >> i >> x;
      i--;
      ret = 0;
      for (int d : divisors){
        ans[d][i % d] += (x - a[i]) * d;
        ins(ans[d][i % d], i % d, d);
        ret = max(ret, get_ans(d));
        its++;
      }
      a[i] = x;
      cout << ret << '\n';
    }
  }();
}
