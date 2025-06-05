#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

const int MN = 500;

template<typename T>
struct Sliding {
  const T e = 0;
  T op(T x, T y) { return x | y; }

  T a[MN], b[MN], acc[MN];
  T pa, pb;
  T val_b;
  Sliding() { val_b = e; pa = pb = 0; }
  void push_back(T x) {
    b[pb++] = x;
    val_b = op(val_b, x);
  }
  void transfer() {
    reverse(b, b + pb);
    memcpy(a, b, pb * sizeof(T));
    pa = pb;
    pb = 0;
    partial_sum(a, a + pa, acc, [&](T x, T y) {
      return op(x, y);
    });
    val_b = e;
  }
  void pop_front() {
    if (pa == 0) {
      transfer();
    }
    pa--;
  }
  T val() {
    if (pa == 0) return val_b;
    return op(val_b, acc[pa - 1]);
  }
  T peek_pop() {
    if (pa == 0) transfer();
    if (pa == 1) return val_b;
    else return op(val_b, acc[pa - 2]);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N, K; cin >> N >> K;
  vector<vector<int>> a(N, vector<int>(N));
  for (int i = 0; i < N; ++i) {
    string s; cin >> s;
    for (int j = 0; j < N; ++j) {
      a[i][j] = s[j] - 'A';
    }
  }
  int all = (1 << K) - 1;
  ll ans = 0;
  for (int i1 = 0; i1 < N; ++i1) {
    vector<int> prod(N);
    for (int i2 = i1; i2 < N; ++i2) {
      for (int j = 0; j < N; ++j) {
        prod[j] |= 1 << a[i2][j];
      }
      Sliding<int> ds;
      int p = 0;
      for (int j = 0; j < N; ++j) {
        ds.push_back(prod[j]);
        while (ds.peek_pop() == all) {
          ds.pop_front();
          p++;
        }
        if (ds.val() == all) {
          ans += p + 1;
        }
      }
    }
  }
  cout << ans << '\n';
}
