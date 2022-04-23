#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

cc_hash_table<string, int> dist;
vector<pair<int, int>> swp = {{0, 1}, {1, 2}, {3, 4}, {4, 5}, {6, 7}, {7, 8},
                              {0, 3}, {3, 6}, {1, 4}, {4, 7}, {2, 5}, {5, 8}};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string st = "";
    for (int i = 0; i < 9; ++i){
        int x; cin >> x;
        st += (x + '0');
    }
    dist[st] = 0;
    queue<string> q; q.push(st);
    while (!q.empty()){
        string v = q.front(); q.pop();
        for (auto [a, b] : swp){
            string to = v; swap(to[a], to[b]);
            if (dist.find(to) == dist.end()){
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
    cout << dist["123456789"] << '\n';
}
