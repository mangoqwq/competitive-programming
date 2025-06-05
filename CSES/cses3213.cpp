#include <algorithm>
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
  int A, B, X; cin >> A >> B >> X;
  if (X > A) {
    cout << -1 << '\n';
    return 0;
  }
  vector<vector<int>> dist(A + 1, vector<int>(B + 1, 1e9));
  struct Move { string mov; int la, lb; };
  vector<vector<Move>> from(A + 1, vector<Move>(B + 1));
  dist[0][0] = 0;
  struct State {
    int a, b, d;
    bool operator<(const State &other) const {
      return d > other.d;
    }
  };
  priority_queue<State> pq;
  pq.emplace(0, 0, 0);
  while (!pq.empty()) {
    auto [a, b, d] = pq.top(); pq.pop();
    if (d != dist[a][b]) continue;
    auto relax = [&](int na, int nb, int nw, string mov) {
      if (dist[na][nb] <= d + nw) return;
      dist[na][nb] = d + nw;
      from[na][nb] = {mov, a, b};
      pq.emplace(na, nb, dist[na][nb]);
    };
    if (a < A) {
      relax(A, b, A - a, "FILL A");
    }
    if (b < B) {
      relax(a, B, B - b, "FILL B");
    }
    if (a) {
      relax(0, b, a, "EMPTY A");
    }
    if (b) {
      relax(a, 0, b, "EMPTY B");
    }
    if (a && b < B) {
      int del = min(a, B - b);
      relax(a - del, b + del, del, "MOVE A B");
    }
    if (a < A && b) {
      int del = min(A - a, b);
      relax(a + del, b - del, del, "MOVE B A");
    }
  }

  int arg_b = ranges::min_element(dist[X]) - dist[X].begin();
  if (dist[X][arg_b] >= 1e9) {
    cout << -1 << '\n';
  }
  else {
    vector<string> moves;
    int a = X, b = arg_b;
    while (a || b) {
      moves.emplace_back(from[a][b].mov);
      tie(a, b) = tie(from[a][b].la, from[a][b].lb);
      debug(a, b);
    }
    ranges::reverse(moves);
    cout << moves.size() << " " << dist[X][arg_b] << '\n';
    for (auto mov : moves) {
      cout << mov << '\n';
    }
  }
}
