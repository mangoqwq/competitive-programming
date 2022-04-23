#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 1;
int N, K, l[M], r[M], ord[M];

int main(){
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) cin >> l[i] >> r[i], ord[i] = i;
    sort(ord + 1, ord + 1 + N, [](int a, int b){ return r[a] < r[b]; });
    map<int, int> mp;
    mp[1] = K;
    int a = 0;
    for (int i = 1; i <= N; ++i){
        int v = ord[i];
        if (mp.begin()->first > l[v]) continue;
        int x = (--mp.upper_bound(l[v]))->first;
        a++; mp[x]--; mp[r[v]]++;
        if (mp[x] == 0) mp.erase(x);
    }
    cout << a << '\n';
}
