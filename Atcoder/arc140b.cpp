#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    string S; cin >> S;

    map<int, int> mp;
    for (int i = 0; i < N; ++i){
        if (S[i] == 'R'){
            int cur = 0;
            for (int j = 1; j < N; ++j){
                if (i + j >= N || i - j < 0) break;
                if (S[i - j] == 'A' && S[i + j] == 'C') cur++;
                else break;
            }
            if (cur) mp[cur]++;
        }
    }
    
    int ans = 0;
    while (!mp.empty()){
        int v = (--mp.end())->first;
        ans++;
        mp[v]--;
        if (mp[v] == 0) mp.erase(v);
        if (v != 1) mp[v - 1]++;
    
        if (mp.empty()) break;
        v = mp.begin()->first;
        ans++;
        mp[v]--;
        if (mp[v] == 0) mp.erase(v);
    }
    cout << ans << '\n';
}

/*
ARCARCARC
ARCRARC
ARCRAC
ACRAC

AARCAARCCC

*/
