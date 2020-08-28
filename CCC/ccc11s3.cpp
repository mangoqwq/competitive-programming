#include <bits/stdc++.h>
#include <string>

using namespace std;

string verify(int uwu, int x, int y){
    if (x<pow(5,uwu-1)||x>pow(5,uwu)-pow(5,uwu-1)-1){
        return "empty";
    }
    if (y>=x||x+y+1>=pow(5,uwu)){
        return "empty";
    }
    if (y>=pow(5,uwu-1)&&y<2*pow(5,uwu-1)&&x>=pow(5,uwu-1)&&x<2*pow(5,uwu-1)){
        return verify(uwu-1,x-pow(5,uwu-1),y-pow(5,uwu-1));
    }
    if (y>=pow(5,uwu-1)&&y<2*pow(5,uwu-1)&&x>=3*pow(5,uwu-1)&&x<4*pow(5,uwu-1)){
        return verify(uwu-1,x-3*pow(5,uwu-1),y-pow(5,uwu-1));
    }
    if (y>=2*pow(5,uwu-1)&&y<3*pow(5,uwu-1)&&x>=2*pow(5,uwu-1)&&x<3*pow(5,uwu-1)){
        return verify(uwu-1,x-2*pow(5,uwu-1),y-2*pow(5,uwu-1));
    }
    return "crystal";

}

int main(){
    int queries,magnification,x,y;
    cin >> queries;
    for (int i=0;i<queries;++i){
        cin >> magnification >> x >> y;
        cout << verify(magnification,x,y) << '\n';
    }
    /*
    for (int i=0;i<124;++i){
        for (int k=0;k<124;++k){
            if (verify(3,k,i)=="empty"){
                cout << "o";
            }
            else{
                cout << " ";
            }
            //cout << verify(2,i,k) << " ";
        }
        cout << '\n';
    }
    */
    
}