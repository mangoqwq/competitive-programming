#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N);
        vector<int> odd, even;
        for (int i = 0; i < N; ++i){
            cin >> a[i];
            if (a[i]%2) odd.push_back(i);
            else even.push_back(i);
        }
        if (odd.size() >= 3){
            cout << "YES" << '\n';
            cout << odd[0]+1 << " " << odd[1]+1 << " " << odd[2]+1 << '\n';
        }
        else if (odd.size() >= 1 && even.size() >= 2){
            cout << "YES" << '\n';
            cout << even[0]+1 << " " << even[1]+1 << " " << odd[0]+1 << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
}
