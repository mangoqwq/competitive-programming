// #include "rail.h"
#include <bits/stdc++.h>
using namespace std;

void findLocation(int n, int first, int location[], int stype[]);
int getDistance(int i, int j);

void findLocation(int N, int first, int location[], int stype[]){
    vector<int> ptype(1e6);
    auto answer = [&](int i, int loc, int typ){
        location[i] = loc;
        stype[i] = typ;
        ptype[loc] = typ;
    };

    vector<vector<int>> dist(N, vector<int>(N));
    int l = 0;
    for (int i = 0; i < N; ++i){
        if (i == l) continue;
        dist[l][i] = getDistance(l, i);
    }

    int r = min_element(dist[0].begin() + 1, dist[0].end()) - dist[0].begin();
    for (int i = 0; i < N; ++i){
        if (i == r) continue;
        dist[r][i] = getDistance(r, i);
    }

    answer(l, first, 1);
    answer(r, first + dist[l][r], 2);

    vector<int> lef, cen, rig;
    for (int i = 0; i < N; ++i){
        if (i == l || i == r) continue;
        if (dist[l][i] == dist[l][r] + dist[r][i] && dist[r][i] < dist[r][l]){
            cen.push_back(i);
        }
        else if (dist[l][i] == dist[l][r] + dist[r][i]) lef.push_back(i);
        else rig.push_back(i);
    }

    for (int i : cen){
        answer(i, location[r] - dist[r][i], 1);
    }

    int far = l;
    sort(lef.begin(), lef.end(), [&](int a, int b){ return dist[r][a] < dist[r][b]; });
    for (int i : lef){
        int tmp = dist[r][far] + getDistance(far, i);
        int pos = location[far] + (tmp - dist[r][i]) / 2;
        if (ptype[pos] == 1) answer(i, location[far] + (tmp - dist[r][far]), 2);
        else answer(i, location[r] - dist[r][i], 1), far = i;
    }

    far = r;
    sort(rig.begin(), rig.end(), [&](int a, int b){ return dist[l][a] < dist[l][b]; });
    for (int i : rig){
        int tmp = dist[l][far] + getDistance(far, i);
        int pos = location[far] - (tmp - dist[l][i]) / 2;
        if (ptype[pos] == 2) answer(i, location[far] - (tmp - dist[l][far]), 1);
        else answer(i, location[l] + dist[l][i], 2), far = i;
    }
}
