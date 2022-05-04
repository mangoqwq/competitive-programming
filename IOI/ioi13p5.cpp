#include <bits/stdc++.h>
using namespace std;

int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {

    sort(X, X + A);
    sort(Y, Y + B);

    vector<int> ord_yx(T);
    for (int i = 0; i < T; ++i){
        ord_yx[i] = i;
    }
    sort(ord_yx.begin(), ord_yx.end(), [&](int i, int j){
        if (S[i] == S[j]){
            return W[i] > W[j];
        }
        return S[i] < S[j];
    });

    auto solve = [&](int ans) -> bool{
        struct Toy{
            int x, y, id;
            bool operator<(const Toy& other) const{
                return x < other.x;
            }
        };
        priority_queue<Toy> q;

        int p = 0;
        for (int i = 0; i < B; ++i){
            while (p < T && S[ord_yx[p]] < Y[i]){
                int t = ord_yx[p];
                q.push({W[t], S[t], t});
                p++;
            }
            for (int j = 0; j < ans; ++j){
                if (q.empty()) break;
                q.pop();
            }
        }
        while (p < T){
            int t = ord_yx[p];
            q.push({W[t], S[t], t});
            p++;
        }

        vector<Toy> vec;
        while (!q.empty()){
            vec.push_back(q.top());
            q.pop();
        }
        
        for (int i = 0; i < A; ++i){
            for (int j = 0; j < ans; ++j){
                if (vec.empty() || vec.back().x >= X[i]) break;
                vec.pop_back();
            }
        }

        return vec.empty();
    };

    int lo = 1, hi = T + 1;
    while (lo < hi){
        int mi = (lo + hi) >> 1;
        if (solve(mi)) hi = mi;
        else lo = mi + 1;
    }

    return (lo == T + 1 ? -1 : lo);
}
