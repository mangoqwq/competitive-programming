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
  vector<int> sa(N), ord(N);
  for (int i = 0; i < N; ++i) {
    cin >> sa[i]; sa[i]--;
    ord[sa[i]] = i;
  }
  ord.push_back(-1);
  string ans(N, '#');
  ans[sa[0]] = 'a';
  for (int i = 1; i < N; ++i) {
    if (ord[sa[i] + 1] > ord[sa[i - 1] + 1]) {
      ans[sa[i]] = ans[sa[i - 1]];
    }
    else {
      if (ans[sa[i - 1]] == 'z') {
        cout << -1 << '\n';
        return 0;
      }
      ans[sa[i]] = ans[sa[i - 1]] + 1;
    }
  }
  cout << ans << '\n';
}
