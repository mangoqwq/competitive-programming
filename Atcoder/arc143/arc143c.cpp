#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X, Y; cin >> N >> X >> Y;
    bool first = 0, second = 0;
    for (int i = 0; i < N; ++i){
        int a; cin >> a;
        a %= (X + Y);
        if (a >= X){
            a -= X;
            first = 1;
        }
        if (a >= Y){
            a -= Y;
            second = 1;
        }
    }
    if (!first) cout << "Second" << '\n';
    else if (!second) cout << "First" << '\n';
    else cout << "Second" << '\n';
}
