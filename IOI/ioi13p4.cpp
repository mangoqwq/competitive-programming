#include <bits/stdc++.h>
using namespace std;

int tryCombination(int S[]);
void answer(int S[], int D[]);
void exploreCave(int N);

void exploreCave(int N) {
    int ans[N], pos[N], guess[N];
    for (int i = 0; i < N; ++i){
        ans[i] = -1;
        pos[i] = -1;
        guess[i] = 0;
    }

    auto flip = [&](const vector<int> &vec, int l, int r){
        for (int i = l; i < r; ++i){
            guess[vec[i]] ^= 1;
        }
    };

    for (int i = 0; i < N; ++i){
        vector<int> vec;
        for (int j = 0; j < N; ++j){
            if (pos[j] == -1){
                vec.push_back(j);
            }
        }

        if (tryCombination(guess) != i){
            flip(vec, 0, N - i);
        }

        int l = 0, r = N - i;
        while (r - l > 1){
            int m = (l + r) >> 1;
            flip(vec, l, m);
            if (tryCombination(guess) != i){
                r = m;
                flip(vec, l, m);
            }
            else{
                l = m;
            }
        }
        pos[vec[l]] = i;
        ans[vec[l]] = guess[vec[l]] ^ 1;
        flip(vec, l, r);
    }

    answer(ans, pos);
}
