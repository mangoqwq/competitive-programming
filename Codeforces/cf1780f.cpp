#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MN = 3e5+1;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> has(MN), psa(MN);
    for (int i = 0; i < N; ++i){
        int x; cin >> x;
        has[x] = 1;
    }
    for (int i = 1; i < MN; ++i){
        psa[i] = psa[i-1] + has[i];
    }
    vector<ll> ans(MN);
    for (int x = 1; x < MN; ++x){
        ll cnt = 0, sub = 0;
        for (int j = x; j < MN; j += x){
            if (has[j]){
                ans[x] += cnt * psa[j-1] - sub;
                cnt++;
                sub += psa[j];
            }
        }
    }
    for (int i = MN-1; i >= 1; --i){
        for (int j = i*2; j < MN; j += i){
            ans[i] -= ans[j];
        }
    }
    cout << ans[1] << '\n';
}
