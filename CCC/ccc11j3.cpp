#include <iostream>

using namespace std;

int main(){
    int x,y,len=2;
    cin >> x >> y;
    while (true){
        if (x<y){
            break;
        } else{
            int temp = y;
            y=x-y;
            x=temp; 
            ++len;
        }
    }
    cout << len;
}