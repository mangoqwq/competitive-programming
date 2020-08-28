#include <bits/stdc++.h>
#include <string>
using namespace std;

int main(){
    //freopen("word.in","r",stdin);
    //freopen("word.out","w",stdout);
    int words,line;
    cin>>words>>line;
    string uwu[words],temp;
    for (int i=0;i<words;++i){
        cin >> temp;
        uwu[i]=temp;
    }
    cout << uwu[0];
    int owo=line-uwu[0].length();
    for (int i=1;i<words;++i){
        if (owo>=uwu[i].length()){
            cout << " ";
            owo-=uwu[i].length();
        }
        else{
            owo=line-uwu[i].length();
            cout << '\n';
        }
        cout << uwu[i];
    }
}