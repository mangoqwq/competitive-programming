#include <iostream>

using namespace std;

int main(){
    int x,count{0},temp;
    float average;
    cin >> x;
    int uwu[x];
    for (int i=0; i<x; ++i){
        cin >> temp;
        uwu[i] = temp;
        average+=temp;
    }
    average/=x;
    for (int i=0; i<x; ++i){
        if (uwu[i]>average){
            count++;
        }
    }
    if (count>(x/2)){
        cout << "Winnie should take the risk";
    }
    else {
        cout << "That's too risky";
    }
}