#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<int> a(N);
    for (int &x : a) cin >> x;
    ll mx = *max_element(a.begin(), a.end());
    ll lo = mx, hi = N * mx, mid;
    while (lo < hi){
        mid = (lo + hi) >> 1;
        ll cur = mid, cnt = 1;
        for (int &x : a){
            if (x > cur){
                cur = mid;
                cnt++;
            }
            cur -= x;
        }
        if (cnt <= K) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
}
