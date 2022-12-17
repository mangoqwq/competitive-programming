#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K, A, B; cin >> N >> K >> A >> B;
    int cnt = 0;
    while (true){
        int rounds = N/A;
        if (K < rounds){
            cnt += K;
            break;
        }
        K -= rounds, K += B;
        cnt += rounds;
    }
    cout << cnt << '\n';
}
