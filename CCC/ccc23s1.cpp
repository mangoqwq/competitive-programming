#include <bits/stdc++.h>

using namespace std;

int main(){
    int N; cin >> N;
    vector<int> a(N+2);
    vector<int> b(N+2);
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= N; ++i){
        cin >> b[i];
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i){
        if (i % 2 == 0){
            ans += a[i];
            ans += b[i];
        }
        if (a[i] == 1 && a[i-1] == 0) ans++;
        if (a[i] == 1 && a[i+1] == 0) ans++;
        if (b[i] == 1 && b[i-1] == 0) ans++;
        if (b[i] == 1 && b[i+1] == 0) ans++;
        if (i % 2 == 1 && (a[i] ^ b[i])) ans++;
    }
    cout << ans << '\n';
}
