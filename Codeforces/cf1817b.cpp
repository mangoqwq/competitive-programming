#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int T; cin >> T;
  while (T--) [&](){
    int N, M; cin >> N >> M;
    vector<vector<int>> adj(N);
    vector<vector<int>> mat(N, vector<int>(N));
    for (int i = 0; i < M; ++i){
      int a, b; cin >> a >> b;
      a--, b--;
      mat[a][b] = 1;
      mat[b][a] = 1;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    for (int i = 0; i < N; ++i){
      if (adj[i].size() < 4) continue;
      set<int> beside;
      for (int to : adj[i]){
        beside.insert(to);
      }

      bool found = 0;
      vector<int> cur, in(N);
      auto dfs = [&](auto self, int v, int l) -> void {
        in[v] = 1;
        cur.push_back(v);
        if (mat[i][v]){
          beside.erase(v);
        }
        for (int to : adj[v]){
          if (to == i && l > 1){
            if (beside.size() >= 2){
              found = 1;
              return;
            }
          }
          if (in[to]) continue;
          self(self, to, l+1);
          if (found) return;
        }
        cur.pop_back();
        if (mat[i][v]){
          beside.insert(v);
        }
      };
      dfs(dfs, i, 0);
      if (found){
        cout << "YES" << '\n';
        cout << cur.size() + 2 << '\n';
        for (int i = 1; i < cur.size(); ++i){
          cout << cur[i-1]+1 << " " << cur[i]+1 << '\n';
        }
        cout << cur.back()+1 << " " << i+1 << '\n';
        int t1 = *(beside.begin());
        int t2 = *(++beside.begin());
        cout << i+1 << " " << t1+1 << '\n';
        cout << i+1 << " " << t2+1 << '\n';
        return;
      }
    }
    cout << "NO" << '\n';
  }();
}
