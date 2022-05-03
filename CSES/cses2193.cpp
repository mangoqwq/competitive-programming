#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<pair<int, int>> v;
    for (int i = 1; i <= N; ++i){
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    for (auto [a, b] : v){
        printf("\\left(%d, %d\\right), ", a, b);
    }
}
