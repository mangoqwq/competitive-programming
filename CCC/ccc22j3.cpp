#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    bool flag = 0;
    for (char c : s){
        if (c == '+') cout << " tighten";
        else if (c == '-') cout << " loosen";
        else if ('0' <= c && c <= '9'){
            if (!flag) cout << " ";
            cout << c, flag = 1;
        }
        else{
            if (flag) flag = 0, cout << '\n';
            cout << c;
        }
    }
}
