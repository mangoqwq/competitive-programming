#include <bits/stdc++.h>

using namespace std;
set<string> owo;

int main(){
    int items, cases; cin >> items >> cases;
    string uwu;
    for (int i=0;i<items;++i){
        cin >> uwu;
        owo.insert(uwu);
    }
    int assignments=0;
    bool end=false;
    for (int i=0,a;i<cases;++i){
        cin >> a;
        end=false;
        for (int ii=0;ii<a;++ii){
            cin >> uwu;
            if (owo.find(uwu)==owo.end()){
                end=true;
            }
        }
        if (!end){
            assignments++;
        }
    }
    cout << assignments << '\n';
}