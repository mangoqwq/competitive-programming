#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }
        sort(a.begin(), a.end(), greater<int>());
        if (a[0] == a[N-1]) cout << "NO" << '\n';
        else{
            swap(a[1], a[N-1]);
            cout << "YES" << '\n';
            for (int x : a) cout << x << " ";
            cout << '\n';
        }
    }
}
