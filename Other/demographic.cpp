#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    int Q; cin >> Q;
    while (Q--){
        int l, r; cin >> l >> r;
        auto lo = lower_bound(a.begin(), a.end(), l);
        auto hi = upper_bound(a.begin(), a.end(), r);
        cout << hi - lo << '\n';
    }
}
