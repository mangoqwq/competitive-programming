#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N), cnt(N+1);
        for (int i = 0; i < N; ++i){
            cin >> a[i];
            cnt[a[i]]++;
        }
        vector<vector<int>> pot(3);
        bool good = 1;
        for (int i = 1; i <= N; ++i){
            if (cnt[i] > 2) good = 0;
            else pot[cnt[i]].push_back(i);
        }
        map<int, int> mp;
        for (int i = 0; i < pot[2].size(); ++i){
            good &= pot[2][i] > pot[0][i];
            mp[pot[2][i]] = pot[0][i];
        }
        if (!good){
            cout << "NO" << '\n';
            continue;
        }

        cout << "YES" << '\n';
        vector<int> seen(N+1), p(N), q(N);
        for (int i = 0; i < N; ++i){
            if (cnt[a[i]] == 2){
                if (seen[a[i]]){
                    p[i] = a[i], q[i] = mp[a[i]];
                }
                else{
                    p[i] = mp[a[i]], q[i] = a[i];
                }
                seen[a[i]] = 1;
            }
            else{
                p[i] = q[i] = a[i];
            }
        }
        for (int i = 0; i < N; ++i){
            cout << p[i] << " ";
        }
        cout << '\n';
        for (int i = 0; i < N; ++i){
            cout << q[i] << " ";
        }
        cout << '\n';
    }
}
