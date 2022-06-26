#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    vector<ll> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    if (v[0] + v[1] < v[2]){
        cout << -1 << '\n';
    }
    else{
        cout << v[2] << '\n';
    }
}
