#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    string a, b; cin >> a >> b;
    while (a.size() || b.size()){
        if (a.empty() ^ b.empty()){
            cout << "NO" << '\n';
            return;
        }
        if (b.back() == a.back()){
            a.pop_back();
            b.pop_back();
        }
        else{
            if (b.back() == 'a'){
                cout << "NO" << '\n';
                return;
            }
            char c = b.back();
            b.pop_back();
            b.push_back(c - 1);
            b.push_back(c - 1);
        }
    }
    cout << "YES" << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        solve();
    }
}
