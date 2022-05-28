#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll N, A, B; cin >> N >> A >> B;
    ll tot = N * (N + 1) / 2;
    ll numA = N / A;
    tot -= A * (numA) * (numA + 1) / 2;
    ll numB = N / B;
    tot -= B * (numB) * (numB + 1) / 2;
    ll C = lcm(A, B);
    ll numC = N / C;
    tot += C * (numC) * (numC + 1) / 2;
    cout << tot << '\n';
}
