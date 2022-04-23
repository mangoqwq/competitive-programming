#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;
using ordered_set = tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    ordered_set s;
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        s.insert({i, x});
    }
    for (int i = 1; i <= N; ++i){
        int idx; cin >> idx;
        cout << s.find_by_order(idx - 1)->second << " ";
        s.erase(s.find_by_order(idx - 1));
    }
}
