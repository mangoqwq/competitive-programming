#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    ordered_set t;
    for (int i = 1; i <= N; ++i) t.insert(i);
    int pos = 0;
    while (!t.empty()){
        pos = (pos + K) % t.size();
        auto it = t.find_by_order(pos);
        cout << *it << " ";
        t.erase(it);
    }
    cout << '\n';
}
