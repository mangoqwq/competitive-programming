#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
 
using namespace std;
using namespace __gnu_pbds;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int N, K, a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> K;
    ordered_set s; s.insert({0, 0});
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        s.insert({a[i], i});
        if (i >= K){
            s.erase({a[i - K], i - K});
            cout << s.find_by_order((K - 1) / 2)->first << " ";
        }
    }
    cout << '\n';
}
