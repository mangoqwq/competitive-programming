#include <iostream>
#include <set>

using namespace std;

int main(){
    int x;
    cin >> x;
    int y;
    set<int> aa;
    for (int i=0;i<x;++i){
        cin >> y;
        aa.insert(y);
    }
    cout << aa.size();
}