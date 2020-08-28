#include <iostream>
#include <string>

using namespace std;

int main(){
    int t=0, s=0, uwu;
    cin >> uwu;
    cin.ignore();
    for (int i=0; i<uwu; i++){
        string temp;
        getline(cin,temp);
        for (int awoo=0;awoo<temp.length();awoo++){
            if (temp[awoo] == 't' || temp[awoo] == 'T'){
                t+=1;
            }
            if (temp[awoo] == 's' || temp[awoo] == 'S'){
                s+=1;
            }
        }
    }
    if (t>s){
        cout << "English";
    }
    else{
        cout << "French";
    }
    return 0;
}