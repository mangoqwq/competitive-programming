#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int get_hash(string s) {
  int hash = 0;
  for (int i = 0; i < (int)s.size(); i++) {
    hash = hash * 13 + s[i] - 'a' + 1;
  }
  return hash;
}


int main(){
  cin.tie(0)->sync_with_stdio(0);
  int N, M; cin >> N >> M;
  int ans = 0;
  string cur = "";
  auto gen = [&](auto self, int i) -> void {
    if (i == N){
      if (get_hash(cur) == M) ans++;
      return;
    }
    for (char c = 'a'; c <= 'z'; ++c){
      cur += c;
      self(self, i+1);
      cur.pop_back();
    }
  };
  gen(gen, 0);
  cout << ans << '\n';
}
