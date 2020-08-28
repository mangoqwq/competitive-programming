#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<
ll,
null_type,
greater_equal<ll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    ordered_set uwu;
    int games; cin >> games;
    ll temp;
    ll total=0;
    for (int i=0;i<games;++i){
        cin >> temp;
        uwu.insert(temp);
        total+=uwu.order_of_key(temp)+1;
    }
    printf("%.2lf\n",total/(double)games);
}