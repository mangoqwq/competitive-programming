#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        int c = 1;
        bool f = 0;
        vector<vector<int>> ans(N+1, vector<int>(N+1));
        for (int i = 1; i <= N; ++i){
            if (i % 2 == 1){
                for (int j = 1; j <= N; ++j){
                    ans[i][j] = c;
                    if (f == 0) c = N*N-c+1;
                    else c = N*N-c + 2;
                    f ^= 1;
                }
            }
            else{
                for (int j = N; j >= 1; --j){
                    ans[i][j] = c;
                    if (f == 0) c = N*N-c + 1;
                    else c = N*N-c + 2;
                    f ^= 1;
                }
            }
        }
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= N; ++j){
                cout << ans[i][j] << " ";
            }
            cout << '\n';
        }
    }
}
