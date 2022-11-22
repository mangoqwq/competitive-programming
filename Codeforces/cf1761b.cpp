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
        if (N <= 2) cout << N << '\n';
        else{
            bool dif = 0;
            for (int i = 1; i < a.size(); ++i){
                if (a[i-1] != a[(i+1)%a.size()]){
                    dif = 1;
                }
            }
            if (dif) cout << N << '\n';
            else cout << N/2+1 << '\n';
        }
    }
}
