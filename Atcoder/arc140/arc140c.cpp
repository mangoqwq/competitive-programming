#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, X; cin >> N >> X;
    vector<int> v(N);
    iota(v.begin(), v.end(), 1);
    v.erase(v.begin() + X - 1);

    vector<int> lef, rig;
    for (int i = 0; i < N / 2; ++i){
        lef.push_back(v[i]);
    }
    for (int i = N - 2; i >= N / 2; --i){
        rig.push_back(v[i]);
    }
    if (N % 2 == 0 && X == N / 2){
        rig.push_back(lef.back()); lef.pop_back();
        swap(lef, rig);
    }

    cout << X << " ";
    while (!lef.empty() || !rig.empty()){
        if (!lef.empty()){
            cout << lef.back() << " ";
            lef.pop_back();
        }
        if (!rig.empty()){
            cout << rig.back() << " ";
            rig.pop_back();
        }
    }
    cout << '\n';
}
