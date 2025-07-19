#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
struct Point { ll x, y; };
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N; cin >> N;
  vector<Point> p(N);
  for (auto &[x, y] : p) {
    cin >> x >> y;
  }
  sort(p.begin(), p.end(), [&](Point a, Point b) {
    return tie(a.x, a.y) < tie(b.x, b.y);
  });
 
  auto dist2 = [&](int i, int j) {
    return (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
  };
 
  ll best = 8e18;
 
  auto go = [&](auto self, int l, int r) -> void {
    if (r - l <= 1) return;
    int m = midpoint(l, r);
    self(self, l, m);
    self(self, m, r);
    vector<Point> tmp(r-l);
    merge(p.begin() + l, p.begin() + m, p.begin() + m, p.begin() + r, tmp.begin(), [&](Point a, Point b) {
      return tie(a.y, a.x) < tie(b.y, b.x);
    });
    copy(tmp.begin(), tmp.end(), p.begin() + l);
 
    vector<int> vec;
    for (int i = l; i < r; ++i) {
      if (abs(p[i].x - p[m].x) * abs(p[i].x - p[m].x) <= best) vec.push_back(i);
    }
    for (int i = 0; i < (int)vec.size(); ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if ((p[vec[i]].y - p[vec[j]].y) * (p[vec[i]].y - p[vec[j]].y) > best) break;
        if (dist2(vec[i], vec[j]) < best) {
          best = dist2(vec[i], vec[j]);
        }
      }
    }
  };
  go(go, 0, N);
  cout << best << '\n';
  // cout << fixed << setprecision(4) << best << '\n';
  // cout << min(ans.first, ans.second) << " " << max(ans.first, ans.second) << '\n';
}
