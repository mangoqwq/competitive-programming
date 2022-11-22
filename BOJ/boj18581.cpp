#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int A, B, C; cin >> A >> B >> C;
    int left = A*B*C, bc = B*C, ac = A*C, ab = A*B;
    int c1 = 1, c2 = 1, c3 = 1;
    struct Item{ int w, a, b, c; };
    vector<Item> ans;
    while (left){
        int sub = min({left, bc, ac, ab});
        ans.push_back({sub, c1, c2, c3});
        left -= sub, bc -= sub, ac -= sub, ab -= sub;
        if (bc == 0) bc = B*C, c1++;
        if (ac == 0) ac = A*C, c2++;
        if (ab == 0) ab = A*B, c3++;
    }
    cout << ans.size() << '\n';
    for (auto [w, a, b, c] : ans){
        cout << w << " " << a << " " << b << " " << c << '\n';
    }
}
