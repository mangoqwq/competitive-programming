#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, X; cin >> N >> X;
        vector<int> a(N);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        if (find(a.begin(), a.end(), X) != a.end()){
            cout << 1 << '\n';
        }
        else if (a.back() > X){
            cout << 2 << '\n';
        }
        else{
            int d = a.back();
            cout << (X+d-1)/d << '\n';
        }
    }
}
