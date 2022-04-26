#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    map<int, int> a;
    function<void(int)> rem = [&](int x){
        a[x]--;
        if (!a[x]) a.erase(x);
    };
    for (int i = 1; i <= N; ++i){
        int x; cin >> x;
        a[x]++;
    }
    vector<int> ans;
    ans.push_back(a.begin()->first);
    rem(ans[0]);
    for (int i = 2; i <= N; ++i){
        auto it = a.lower_bound(M - ans.back());
        if (it == a.end()){
            cout << -1 << '\n';
            return 0;
        }
        int x = it->first;
        rem(x);
        ans.push_back(x);
    }
    for (int x : ans) cout << x << " ";
    cout << '\n';
}
