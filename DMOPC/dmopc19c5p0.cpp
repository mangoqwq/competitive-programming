#include <bits/stdc++.h>

using namespace std;

int main(){
    int users,cutoff; cin >> users >> cutoff;
    string name; int score;
    for (int i=0;i<users;++i){
        cin >> name >> score;
        if (score>cutoff){
            cout << name << " will advance" << '\n';
        }
        else{
            cout << name << " will not advance" << '\n';
        }
    }
}