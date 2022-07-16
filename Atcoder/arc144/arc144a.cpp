#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    cout << 2 * N << '\n';
    vector<int> v;
    while (N){
        int sub = min(4, N);
        v.push_back(sub);
        N -= sub;
    }
    reverse(v.begin(), v.end());
    for (int x : v) cout << x;
    cout << '\n';
}
