#include <bits/stdc++.h>

using namespace std;

int find_best(int n);
std::vector<int> ask(int i);

int find_best(int N) {


    vector<vector<int>> asks(N);
    vector<int> sum(N, -1);
    
    int mx = 0;
    int L = 0;
    for (int &i = L; i < min(500, N); ++i){
        asks[i] = ask(i);
        sum[i] = asks[i][0] + asks[i][1];
        mx = max(mx, sum[i]);
        if (sum[i] > 21){
            break;
        }
    }
    if (L == N || L == 500){
        L--;
    }

    function<void(vector<int>, int, int)> go = [&](vector<int> v, int cl, int cr){
        while (!v.empty()){
            int m = v.size() / 2;
            int i = v[m];

            asks[i] = ask(i);
            sum[i] = asks[i][0] + asks[i][1];
            
            if (sum[i] < mx){
                v.erase(v.begin() + m);
            }
            else{
                int l = asks[i][0] - cl;
                int r = asks[i][1] - cr;

                vector<int> lv, rv;
                for (int j = 0; j < m; ++j){
                    lv.push_back(v[j]);
                }
                for (int j = m + 1; j < v.size(); ++j){
                    rv.push_back(v[j]);
                }

                if (l) go(lv, cl, asks[i][1]);
                if (r) go(rv, asks[i][0], cr);
                return;
            }
        }
    };

    int cl = 0;
    for (int i = 0; i <= L; ++i){
        if (sum[i] < mx){
            cl++;
        }
    }

    vector<int> v;
    for (int i = L; i < N; ++i){
        v.push_back(i);
    }

    go(v, cl, 0);
    for (int i = 0; i < N; ++i){
        if (sum[i] == 0){
            return i;
        }
    }

    assert(false);
    return 0;
}
