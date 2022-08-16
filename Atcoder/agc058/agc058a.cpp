#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N; N *= 2;
    vector<int> a(N);
    for (int i = 0; i < N; ++i){
        cin >> a[i];
    }
    vector<int> ans;
    if (a[0] > a[1]){
        swap(a[0], a[1]);
        ans.push_back(0);
    }
    for (int i = 2; i < N-1; i+=2){
        if (a[i-1] < min(a[i], a[i+1])){
            swap(a[i-1], a[i]);
            ans.push_back(i-1);
        }
        else if (a[i] > a[i+1]){
            swap(a[i], a[i+1]);
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (int x : ans) cout << x+1 << " ";
    cout << '\n';
}
