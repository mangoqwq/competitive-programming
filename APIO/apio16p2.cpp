#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 3e5+1;

// Modified from Nyaan's library
// https://nyaannyaan.github.io/library/data-structure/slope-trick.hpp
struct SlopeTrick {
  using ll = long long;
  ll lazx, mn;
  priority_queue<ll> L;
  priority_queue<ll, vector<ll>, greater<ll>> R;

  SlopeTrick() : lazx(0), mn(0) { }

  pair<ll, ll> get_min() {
    ll x = L.empty() ? R.empty() ? 0 : R.top() : L.top();
    return {x + lazx, mn};
  }

  // f(x) <- f(x - a)
  void shift_x(ll a) { lazx += a; }
  // f(x) <- f(x) + a
  void shift_y(ll a) { mn += a; }

  /**
   * add (x-a)_+
   *           /
   *          /
   *   _____ /
   */
  void add_xma(ll a) {
    a -= lazx;
    if (!L.empty()) mn += max(0LL, L.top() - a);
    L.push(a);
    R.push(L.top());
    L.pop();
  }

  /**
   * add (a-x)_+
   *   \
   *    \
   *     \_____
   */
  void add_amx(ll a) {
    a -= lazx;
    if (!R.empty()) mn += max(0LL, a - R.top());
    R.push(a);
    L.push(R.top());
    R.pop();
  }

  void add_abs_xma(ll a) { add_xma(a), add_amx(a); }

  //  \_/ -> \__
  void accum_min_right() {
    decltype(R) dummy;
    swap(dummy, R);
  }

  // \_/ -> __/
  void accum_min_left() {
    decltype(L) dummy;
    swap(dummy, L);
  }

  SlopeTrick& transform(ll c){
      ll tmp = R.top();
      accum_min_right();
      R.push(tmp + c);
      
      tmp = L.top();
      L.pop();
      L.push(tmp + c);
      return *this;
  }
  
  SlopeTrick& operator+=(SlopeTrick &rhs){
      decltype(rhs.L) rhsL = rhs.L;
      while (!rhsL.empty()){
          ll x = rhsL.top();
          rhsL.pop();
          add_amx(x);
      }
      decltype(rhs.R) rhsR = rhs.R;
      while (!rhsR.empty()){
          ll x = rhsR.top();
          rhsR.pop();
          add_xma(x);
      }
      mn += rhs.mn;
      return *this;
  }

  int getsz(){ return L.size() + R.size(); }
};

int n, m, c[MAXN];
vector<int> adj[MAXN];
using fun = SlopeTrick;

fun dfs(int v){
    fun ret;
    // explosive
    if (adj[v].empty()){
        ret.add_abs_xma(0);
        return ret;
    }
    // junction
    else{
        for (int to : adj[v]){
            fun child = dfs(to);
            child.transform(c[to]);
            if (child.getsz() > ret.getsz()){
                swap(child, ret);
            }
            ret += child;
        }
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 2; i <= n + m; ++i){
        int par; cin >> par;
        adj[par].push_back(i);
        cin >> c[i];
    }
    fun ans = dfs(1);
    cout << ans.get_min().second << '\n';
}
