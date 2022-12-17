#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        string s; cin >> s;
        int cnta = 0, cntb = 0;
        for (int i = 0; i < N-1; ++i){
            if (s[i] == '0') cnta++, cntb = 0;
            if (s[i] == '1') cntb++, cnta = 0;
            cout << i+2 - max(cntb, cnta) << " ";
        }
        cout << '\n';
    }
}
