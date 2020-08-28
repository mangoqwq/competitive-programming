#include <iostream>
#include <queue>
using namespace std;

int main(){
    int owo, x, uwu{0}, index{0};
    cin >> owo;
    cin >> x;
    x+=3;
    int cars[x];
    cars[0]=0;
    cars[1]=0;
    cars[2]=0;
    for (int i=3;i<x;++i){
        int temp;
        cin >> temp;
        cars[i]=temp;
    }
    for (int i=0;i<x-3;++i){
        if (cars[index]+cars[index+1]+cars[index+2]+cars[index+3]<=owo){
            uwu+=1;
            index+=1;
        } else{
            break;
        }
    }
    cout << uwu;
    return 0;
}