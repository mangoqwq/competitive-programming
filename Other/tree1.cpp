#include <iostream>

using namespace std;

int main(){
    int uwu[4][4];
    int a,b,c,d;
    for (int i=0;i<4;++i){
        cin >> a >> b >> c >> d;
        uwu[i][0]=a;
        uwu[i][1]=b;
        uwu[i][2]=c;
        uwu[i][3]=d;
    }
    int tree=1,count=0;
    for (int i=0;i<4;++i){
        for (int k=i+1;k<4;++k){
            if (uwu[i][k]!=uwu[k][i]){
                tree=0;
            }
            else{
                if (uwu[i][k]==1){
                    count+=1;
                }
            }
        }
    }
    if (uwu[0][0]==1 || uwu[1][1]==1 || uwu[2][2]==1 || uwu[3][3]==1){
        tree=0;
    }
    int temp=0;
    for (auto&&x:uwu){
        for (auto&&y:x){
            temp+=y;
        }
        if (temp==0){
            tree=0;
        }
        temp=0;
    }
    if (count!=3){
        tree=0;
    }
    if (!tree){
        cout << "No" << '\n';
    }
    else{
        cout <<"Yes"<<'\n';
    }
    return 0;
}