#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X; cin >> N >> X;
    map<int, int> a;
    for (int i = 0; i < N; ++i){
        int x; cin >> x;
        a[x]++;
    }
    for (int i = 1; i < X; ++i){
        if (!a.count(i)) continue;
        if (a[i] % (i+1)){
            cout << "No" << '\n';
            return 0;
        }
        a[i+1] += a[i] / (i+1);
    }
    cout << "Yes" << '\n';

}
