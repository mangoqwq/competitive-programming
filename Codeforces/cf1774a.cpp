#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        string s; cin >> s;
        int tot = s[0] - '0';
        for (int i = 1; i < N; ++i){
            if (tot == 1){
                cout << "-";
                tot -= s[i] - '0';
            }
            else{
                cout << "+";
                tot += s[i] - '0';
            }
        }
        cout << '\n';
    }
}
