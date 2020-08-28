#include <bits/stdc++.h>

using namespace std;
int badproblem[21];
map<int,int> m;
int menu[5];
int uwu[5];

int main(){
    int k; cin >> k;
    for (int i=1,a;i<k+1;++i){
        cin >> a;
        badproblem[i]=a;
    }
    int menucost; cin >> menucost;
    for (int i=1,a;i<5;++i){
        cin >> a;
        m.insert({a,i});
        menu[i]=a;
    }
    int meals; cin >> meals;
    int cost=0;
    for (int i=0,a;i<meals;++i){
        cin >> a;
        if (m[a]){
            uwu[m[a]]++;
        }
        else{
            cost+=badproblem[a];
        }
    }
    while (uwu[1]+uwu[2]+uwu[3]+uwu[4]!=0){
        int temp=0;
        if (uwu[1]!=0){
            uwu[1]--;
            temp+=badproblem[menu[1]];
        }
        if (uwu[2]!=0){
            uwu[2]--;
            temp+=badproblem[menu[2]];
        }
        if (uwu[3]!=0){
            uwu[3]--;
            temp+=badproblem[menu[3]];
        }
        if (uwu[4]!=0){
            uwu[4]--;
            temp+=badproblem[menu[4]];
        }
        cost+=min(menucost,temp);
    }
    cout << cost << '\n';
}