// #include "boxes.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long long delivery(int N, int K, int L, int p[]);

ll delivery(int N, int K, int LEN, int p[]) {
    vector<int> lef(K, 0), rig(K, 0);
    for (int i = 0; i < N; ++i){
        if (p[i] <= LEN / 2) lef.push_back(p[i]);
        else rig.push_back(LEN - p[i]);
    }
    reverse(rig.begin() + K, rig.end());

    int L = lef.size(), R = rig.size();
    vector<ll> costl(L), costr(R);
    for (int i = K; i < L; ++i){
        costl[i] = lef[i] * 2 + costl[i - K];
    }
    for (int i = K; i < R; ++i){
        costr[i] = rig[i] * 2 + costr[i - K];
    }

    ll ans = costl.back() + costr.back();
    for (int l = 0; l <= K; ++l){
        int r = K - l;
        ll cur = LEN;
        if (L - 1 - l >= 0) cur += costl[L - 1 - l];
        if (R - 1 - r >= 0) cur += costr[R - 1 - r];
        ans = min(ans, cur);
    }
    return ans;
}
