#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

const int MN = 3000;
const int SZ = 2 * MN * MN;
char a[MN][MN + 2];
short fward[SZ], bward[SZ];
short up[MN][MN], down[MN][MN], lef[MN][MN], rig[MN][MN];
short rems[MN + 1][MN], poi[MN + 1];
short fen[MN + 1];

template <typename T>
struct Fenwick {
  int N = MN;
  [[gnu::always_inline]] void set_mx(int _N) {
    N = _N;
  }
  [[gnu::always_inline]] void ins(int i, T val) {
    for (++i; i < N + 1; i += i & -i) fen[i] += val;
  }
  [[gnu::always_inline]] T qry(int i) {
    T ret(0);
    for (++i; i; i -= i & -i) ret += fen[i];
    return ret;
  }
  [[gnu::always_inline]] T qry(int l, int r) { return qry(r - 1) - qry(l - 1); }
};

[[gnu::always_inline]] int calc(int i, int j) {
  return (i - j + MN) * MN + i;
}

struct Clock {
  chrono::steady_clock::time_point start;
  Clock() { reset(); }
  void reset() { start = chrono::steady_clock::now(); }
  long long elapsed() {
    auto now = chrono::steady_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(now - start).count();
  }
};


int main() {
  // cin.tie(0)->sync_with_stdio(0);
  int N, K; cin >> N >> K;
  string empty;
  getline(cin, empty);
  Clock clock;
  vector<ll> ans(K);
  for (int i = 0; i < N; ++i) {
    fgets(a[i], N + 2, stdin);
    // fgets()
    // string s; cin >> s;
    // for (int j = 0; j < N; ++j) {

    //   a[calc(i, j)] = s[j] - 'A';
    // }
  }
  cerr << clock.elapsed() << '\n';
  clock.reset();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i == 0) up[i][j] = 1;
      else up[i][j] = up[i-1][j] * (a[i][j] == a[i-1][j]) + 1;
      if (j == 0) lef[i][j] = 1;
      else lef[i][j] = lef[i][j-1] * (a[i][j] == a[i][j-1]) + 1;
      bward[calc(i,j)] = min(up[i][j], lef[i][j]);
    }
  }
  for (int i = N-1; i >= 0; --i) {
    for (int j = N-1; j >= 0; --j) {
      if (i == N-1) down[i][j] = 1;
      else down[i][j] = down[i+1][j] * (a[i][j] == a[i+1][j]) + 1;
      if (j == N-1) rig[i][j] = 1;
      else rig[i][j] = rig[i][j+1] * (a[i][j] == a[i][j+1]) + 1;
      fward[calc(i,j)] = min(down[i][j], rig[i][j]);
    }
  }
  cerr << clock.elapsed() << '\n';
  clock.reset();
  vector<pair<int, int>> srcs;
  for (int s = 0; s < N; ++s) {
    srcs.emplace_back(0, s);
    if (s) srcs.emplace_back(s, 0);
  }
  Fenwick<int> bit;
  for (auto [i, j] : srcs) {
    int sub = min(i, j);
    bit.set_mx(min(N - i, N - j) + 1 - sub);
    while (i < N && j < N) {
      // debug(i, j, calc(i, j));
      int idx = min(i, j) - sub;
      bit.ins(idx, 1);
      for (int k = 0; k < poi[idx]; ++k) {
        bit.ins(rems[idx][k], -1);
      }
      poi[idx] = 0;
      int ni = idx + fward[calc(i,j)];
      rems[ni][poi[ni]++] = idx;
      int add = bit.qry(idx - bward[calc(i,j)] + 1, idx + 1);
      ans[a[i][j] - 'A'] += add;
      i++, j++;
    }
    int idx = min(i, j) - sub;
    for (int k = 0; k < poi[idx]; ++k) {
      bit.ins(rems[idx][k], -1);
    }
    poi[idx] = 0;
  }
  cerr << clock.elapsed() << '\n';
  clock.reset();
  for (int i = 0; i < K; ++i) {
    cout << ans[i] << '\n';
  }
}
