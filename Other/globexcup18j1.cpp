#include <iostream>
#include <float.h>
#include <string>

using namespace std;

int main(){
    int up=0,down=0,uwu;
    cin>>uwu;
    string x;
    for (int i=0; i<uwu; ++i){
        cin>>x;
        double temp = stoi(x);
        double temp1 = stod(x);
        //cout << temp1-temp << '\n';
        if (temp1-temp<0.5){down++;}
        else {up++;}
    }
    cout << up << '\n' << down << '\n';
}