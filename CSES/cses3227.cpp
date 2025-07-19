#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

template <class T, class Cmp = less<T>> struct LiChaoTree {
  using Line = pair<T, T>; int N; Cmp cmp; T INF;
  vector<Line> TR; vector<T> X;
  T eval(Line l, int i) const { return l.first*X[i]+l.second; }
  bool majorize(Line a, Line b, int l, int r) {
    return !cmp(eval(a, l), eval(b, l))
        && !cmp(eval(a, r), eval(b, r));
  }
  int cInd(T x) const {
    return lower_bound(X.begin(), X.end(), x) - X.begin();
  }
  int fInd(T x) const {
    return upper_bound(X.begin(), X.end(), x) - X.begin() - 1;
  }
  LiChaoTree(const vector<T> &xs, Cmp cmp = Cmp(),
             T inf = numeric_limits<T>::max())
      : cmp(cmp), INF(min(inf, -inf, cmp)), X(xs) {
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    N = X.size();
    TR.assign(N == 0 ? 0 : 1 << __lg(N*4-1), Line(T(), INF));
  }
  void addLine(int k, int tl, int tr, Line line) {
    if (majorize(line, TR[k], tl, tr)) swap(line, TR[k]);
    if (majorize(TR[k], line, tl, tr)) return;
    if (cmp(eval(TR[k], tl), eval(line, tl))) swap(line,TR[k]);
    int m=tl+(tr-tl)/2; if (!cmp(eval(line,m),eval(TR[k],m))) {
      swap(line, TR[k]); addLine(k * 2, tl, m, line);
    } else addLine(k * 2 + 1, m + 1, tr, line);
  }
  void addLineSegment(
      int k, int tl, int tr, int l, int r, Line line) {
    if (r < tl || tr < l) return;
    if (l <= tl && tr <= r) {addLine(k, tl, tr, line); return;}
    int m = tl + (tr - tl) / 2;
    addLineSegment(k * 2, tl, m, l, r, line);
    addLineSegment(k * 2 + 1, m + 1, tr, l, r, line);
  }
  T getMax(int k, int tl, int tr, int i) const {
    T ret = eval(TR[k], i); if (tl == tr) return ret;
    int m = tl + (tr - tl) / 2;
    if (i <= m) return max(ret, getMax(k * 2, tl, m, i), cmp);
    else return max(ret, getMax(k * 2 + 1, m + 1, tr, i), cmp);
  }
  void addLine(T m, T b) { addLine(1, 0, N - 1, Line(m, b)); }
  void addLineSegment(T m, T b, T l, T r) {
    debug(m, b, l, r);
    int li = cInd(l), ri = fInd(r); if (li <= ri)
      addLineSegment(1, 0, N - 1, li, ri, Line(m, b));
  }
  T getMax(T x) const { return getMax(1, 0, N - 1, cInd(x)); }
  void clear() { fill(TR.begin(), TR.end(), Line(T(), INF)); }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int N, K; cin >> N >> K;
  vector<ll> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  vector<int> ord(N);
  iota(ord.begin(), ord.end(), 0);
  ranges::sort(ord, {}, [&] (int i) { return a[i]; });
  set<int> in = {-1, N};
  vector<ll> xs(N);
  iota(xs.begin(), xs.end(), 0);
  LiChaoTree<ll> lct(xs);
  for (int i : ord) {
    int l = *(--in.lower_bound(i)) + 1;
    int r = *in.lower_bound(i) - 1;
    debug(i, l, r);
    int len = min(r - l + 1, K);
    lct.addLineSegment(0, len * a[i], l + len - 1, r - len + K);
    lct.addLineSegment(-a[i], (r - len + K) * a[i] + len * a[i], r - len + K, N - 1);
    lct.addLineSegment(a[i], -(l - 1) * a[i], l, min(r, l + K - 1));
    in.insert(i);
  }
  for (int i = K; i <= N; ++i) {
    cout << lct.getMax(i - 1) << (i == N ? '\n' : ' ');
  }
}
