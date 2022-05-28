#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N, L, R; cin >> N >> L >> R;
    vector<int> a(N);
    iota(a.begin(), a.end(), 0);
    vector<int> ans(N);
    int l = -1, r = -1;
    for (int i = 0; i < N; ++i){
        int cnt = N - i - 1;
        if (L == 0 && R == 0){
            ans[i] = a[i];
        }
        else if (L == 0){
            if (l == -1 && r == -1){
                l = i, r = N;
            }
            if (cnt >= R){
                vector<int> vec;
                for (int j = l; j < r; ++j){
                    vec.push_back(a[j]);
                }
                for (int j = 0; j < R + 1; ++j){
                    swap(vec[0], vec[j]);
                }
                for (int j = i; j < N; ++j){
                    ans[j] = vec[j - i];
                }
                R = 0;
                i = N;
            }
            else{
                ans[i] = a[r - 1];
                r--;
                R -= cnt;
            }
        }
        else if (cnt >= L){
            for (int j = i + L; j < min(i + R + 1, N); ++j){
                swap(a[i], a[j]);
            }
            ans[i] = a[i];
            L = 0;
            R = max(R - cnt, 0LL);
        }
        else{
            ans[i] = a[i];
            L -= cnt;
            R -= cnt;
        }
    }
    for (int i = 0; i < N; ++i){
        cout << ans[i] + 1 << " ";
    }
    cout << '\n';
}
