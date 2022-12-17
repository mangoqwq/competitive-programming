#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string S, T; cin >> S >> T;
    while (T.size() != S.size()){
        char c = T.back();
        T.pop_back();
        if (c == 'B'){
            reverse(T.begin(), T.end());
        }
    }
    cout << (S == T) << '\n';
}
