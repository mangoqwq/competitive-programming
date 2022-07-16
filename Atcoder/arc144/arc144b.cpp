#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, A, B; cin >> N >> A >> B;
    vector<int> a(N);
    for (int i = 0; i < N; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int lo = 1, hi = 1e9;
    while (lo < hi){
        int mi = (lo + hi + 1) >> 1;
        
        ll sum = 0;
        for (int i = 0; i < N; ++i){
            if (a[i] < mi){
                sum -= (mi - a[i] + A - 1) / A;
            }
            if (a[i] > mi){
                sum += (a[i] - mi) / B;
            }
        }
        if (sum >= 0) lo = mi;
        else hi = mi - 1;
    }
    cout << lo << '\n';
}
