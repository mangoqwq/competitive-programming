#include <iostream>

using namespace std;

int main(){
    bool x[1000001];
    for (int i{0};i<1000001;++i){
        x[i] = false;
    }
    int owo,uwu,count=0;
    cin >> owo;
    for (int i=0;i<owo;++i){
        cin >> uwu;
        if (uwu!=0){
            x[uwu]=true;
        }
    }
    for (int i=0;i<1000001;++i){
        if (x[i]==true){
            count +=1;
        }
    }
    cout << owo-count;
}