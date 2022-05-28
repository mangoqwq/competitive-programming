#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    map<int, int> mp;
    int Q; cin >> Q;
    while (Q--){
        int op; cin >> op;
        if (op == 1){
            int x; cin >> x;
            mp[x]++;
        }
        if (op == 2){
            int x, c; cin >> x >> c;
            mp[x] -= min(mp[x], c);
            if (mp[x] == 0) mp.erase(x);
        }
        if (op == 3){
            cout << (--mp.end())->first - mp.begin()->first << '\n';
        }
    }
}
