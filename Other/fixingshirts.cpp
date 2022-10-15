#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    struct Shirt{ bool s; int c; };
    vector<Shirt> a(N), b(M);
    vector<int> comp;
    for (int i = 0; i < N; ++i){
        char c; int s; cin >> c >> s;
        a[i] = {c == 'L', s};
        comp.push_back(s);
    }
    for (int i = 0; i < M; ++i){
        char c; int s; cin >> c >> s;
        b[i] = {c == 'L', s};
        comp.push_back(s);
    }

    sort(comp.begin(), comp.end());
    comp.resize(unique(comp.begin(), comp.end()) - comp.begin());

    vector<vector<int>> need(2, vector<int>(N + M));
    vector<int> need_sz(2);
    for (auto [s, c] : a){
        c = lower_bound(comp.begin(), comp.end(), c) - comp.begin();
        need[s][c]++;
        need_sz[s]++;
    }

    vector<vector<int>> have(2, vector<int>(N + M));
    vector<int> have_sz(2);
    for (auto [s, c] : b){
        c = lower_bound(comp.begin(), comp.end(), c) - comp.begin();
        if (need[s][c]){
            need[s][c]--;
            need_sz[s]--;
        }
        else{
            have[s][c]++;
            have_sz[s]++;
        }
    }

    int ans = 0;
    for (int sz = 0; sz <= 1; ++sz){
        int can = need_sz[sz] - have_sz[sz];
        for (int c = 0; c < N + M; ++c){
            while (need[sz][c]){
                if (can > 0 && have[sz ^ 1][c]){
                    have[sz ^ 1][c]--;
                    have_sz[sz ^ 1]--;
                    need[sz][c]--;
                    need_sz[sz]--;
                    ans++;
                    can--;
                }
                else{
                    break;
                }
            }
        }
    }

    for (int sz = 0; sz <= 1; ++sz){
        ans += need_sz[sz];
        if (need_sz[sz] > have_sz[sz]){
            ans += need_sz[sz] - have_sz[sz];
        }
    }
    cout << ans << '\n';
}
