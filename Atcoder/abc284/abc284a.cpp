#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; ++i) cin >> s[i];
    reverse(s.begin(), s.end());
    for (int i = 0; i < N; ++i){
        cout << s[i] << '\n';
    }
}
