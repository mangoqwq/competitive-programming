// #include "scales.h"
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

void init(int T);
void orderCoins();
void answer(int W[]);

int getMedian(int A, int B, int C);
int getHeaviest(int A, int B, int C);
int getLightest(int A, int B, int C);
int getNextLightest(int A, int B, int C, int D);

vector<vector<int>> ords;
struct Query{ int a, b, c, d, op; };
vector<Query> nxt;

int query(int op, int v, int A, int B, int C, int D = 0){
    vector<pii> tmp = {{ords[v][A - 1], A}, {ords[v][B - 1], B}, {ords[v][C - 1], C}};
    sort(tmp.begin(), tmp.end());
    if (op == 3){
        if (tmp[0].first > ords[v][D - 1]) return tmp[0].second;
        if (tmp[1].first > ords[v][D - 1]) return tmp[1].second;
        if (tmp[2].first > ords[v][D - 1]) return tmp[2].second;
        return tmp[0].second;
    }
    else{
        return tmp[op].second;
    }
}

const int Q = 6;

bool dfs(int v, int dep, const vector<int> &valid){

    if (nxt.size() <= v){
        nxt.resize(v + 1);
    }

    if (valid.size() == 1){
        nxt[v].op = valid[0];
        return 1;
    }
    if (valid.size() == 0) return 1;
    if (dep == Q) return 0;


    for (int A = 1; A <= 6; ++A){
        for (int B = A + 1; B <= 6; ++B){
            for (int C = B + 1; C <= 6; ++C){

                for (int op = 0; op <= 3; ++op){
                    for (int D = 1; D <= (op == 3 ? 6 : 1); ++D){
                        
                        if (op == 3 && (D == A || D == B || D == C)){
                            continue;
                        }

                        vector<int> next_valid[3];
                        for (int i : valid){
                            int x = query(op, i, A, B, C, D);
                            if (x == A) next_valid[0].push_back(i);
                            if (x == B) next_valid[1].push_back(i);
                            if (x == C) next_valid[2].push_back(i);
                        }

                        bool skip = 0;
                        for (int i = 0; i < 3; ++i){
                            if (next_valid[i].size() > 729 / pow(3, dep + 1)) skip = 1;
                        }
                        if (skip) continue;

                        if (dfs(3 * v + 0, dep + 1, next_valid[0]) &&
                            dfs(3 * v + 1, dep + 1, next_valid[1]) &&
                            dfs(3 * v + 2, dep + 1, next_valid[2])){
                            
                            nxt[v] = {A, B, C, D, op};
                            return 1;
                        }

                    }
                }

            }
        }
    }
    return 0;
}

void init(int T){
    vector<int> permutation = {1, 2, 3, 4, 5, 6};
    do{
        ords.push_back(permutation);
    } while (next_permutation(permutation.begin(), permutation.end()));

    vector<int> valid;
    for (int i = 0; i < 720; ++i){
        valid.push_back(i);
    }

    dfs(1, 0, valid);
}

void orderCoins(){
    int v = 1;
    while (true){
        if (nxt[v].a == 0){
            int ans[6];
            for (int i = 0; i < 6; ++i){
                ans[ords[nxt[v].op][i] - 1] = i + 1;
            }
            answer(ans);
            return;
        }

        int x;
        auto [A, B, C, D, op] = nxt[v];

        if (op == 0){
            x = getLightest(A, B, C);
        }
        if (op == 1){
            x = getMedian(A, B, C);
        }
        if (op == 2){
            x = getHeaviest(A, B, C);
        }
        if (op == 3){
            x = getNextLightest(A, B, C, D);
        }

        if (x == A) v = 3 * v + 0;
        if (x == B) v = 3 * v + 1;
        if (x == C) v = 3 * v + 2;
    }
}
