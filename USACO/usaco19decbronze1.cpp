#include <bits/stdc++.h>

using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

int main(){
    int sessions,cows;
    cin >> sessions >> cows;
    set<int> uwu[cows+1];

    int temp;
    vector<int> first;
    for (int i=0;i<cows;++i){
        cin >> temp;
        first.push_back(temp);
        for (int k=0;k<i;++k){
            uwu[first[k]].insert(temp);
        }
    }

    for (int e=1;e<sessions;++e){
        vector<int> second;
        for (int i=0;i<cows;++i){
            cin >> temp;
            second.push_back(temp);
            for (int k=0;k<i;++k){
                if (uwu[temp].find(second[k])!=uwu[temp].end()){
                    uwu[temp].erase(second[k]);
                }
            }
        }
    }
    int left=0;
    for (auto&&x:uwu){
        for (auto&&y:x){
            left++;
        }
    }
    cout << left;

}