#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N, M; cin >> N >> M;
        int T = N*M;
        string s; cin >> s;
        vector<int> row(T);
        vector<int> eve(T+M);
        int first_row = 0;
        set<int> cols;
        for (int i = 0; i < T; ++i){
            if (s[i] == '1'){
                eve[i] += 1;
                eve[i+M] -= 1;
                cols.insert(i % M);
            }

            first_row += eve[i];
            row[i] = (i < M ? 0 : row[i-M]) + (first_row > 0);
            cout << row[i] + cols.size() << " ";
        }
        cout << '\n';
    }
}
