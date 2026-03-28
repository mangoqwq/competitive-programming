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
    int N; cin >> N;
    struct Item { ll tot, num, badness; };
    auto geq = [&](Item a, Item b) {
      return 1LL * a.tot * b.num >= 1LL * b.tot * a.num;
    };
    auto combine = [&](Item a, Item b) {
      Item ret = {a.tot + b.tot, a.num + b.num};
      if (a.num + b.num == 2) {
        ret.badness = 1;
      }
      else if (1LL * a.tot * b.num == 1LL * b.tot * a.num) {
        if (a.badness == 2) ret.badness = 2;
        else if (a.badness == 1) ret.badness = b.badness;
        else if (a.badness == 0) ret.badness = 0;
      }
      else {
        ret.badness = 2;
      }
      return ret;
    };
    vector<Item> q;
    for (int i = 0; i < N; ++i) {
      int x; cin >> x;
      Item cur = { x, 1, 1 };
      while (!q.empty() && geq(q.back(), cur)) {
        cur = combine(q.back(), cur);
        q.pop_back();
      }
      q.push_back(cur);
    }
    if (q.size() == 1 && q.back().badness == 2) {
      cout << "NO" << '\n';
    }
    else {
      cout << "YES" << '\n';
    }
  }();
}
