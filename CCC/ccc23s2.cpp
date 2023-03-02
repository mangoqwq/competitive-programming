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

    vector<int> ans(N+1, 1e9);
    for (int i = 0; i < N; ++i){
        int acc = 0;
        ans[1] = min(ans[1], acc);
        for (int j = 1; i-j >= 0 && i+j < N; ++j){
            acc += abs(a[i-j] - a[i+j]);
            ans[2*j+1] = min(ans[2*j+1], acc);
        }
    }

    for (int i = 0; i < N; ++i){
        int acc = 0;
        for (int j = 1; i-j+1 >= 0 && i+j < N; ++j){
            acc += abs(a[i-j+1] - a[i+j]);
            ans[2*j] = min(ans[2*j], acc);
        }
    }
    
    for (int i = 1; i <= N; ++i){
        cout << ans[i] << (i == N ? '\n' : ' ');
    }
}
