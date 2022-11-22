#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, a, b; cin >> N >> a >> b;
        if (a == N && b == N) cout << "Yes" << '\n';
        else if (a+b >= N-1) cout << "No" << '\n';
        else cout << "Yes" << '\n';
    }
}
