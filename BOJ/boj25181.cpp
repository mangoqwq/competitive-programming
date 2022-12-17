#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> a(N);
    vector<int> ord(N);
    for (int i = 0; i < N; ++i){
        cin >> a[i];
        ord[i] = i;
    }
    sort(ord.begin(), ord.end(), [&](int i, int j){
        return a[i] < a[j];
    });
    vector<int> mov = ord;
    vector<int> ans(N);
    rotate(mov.begin(), mov.begin() + N/2, mov.end());
    for (int i = 0; i < N; ++i){
        ans[ord[i]] = a[mov[i]];
    }
    bool good = 1;
    for (int i = 0; i < N; ++i){
        good &= ans[i] != a[i];
    }
    if (!good) cout << -1 << '\n';
    else{
        for (int i = 0; i < N; ++i){
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}
