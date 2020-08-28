#include <bits/stdc++.h>

using namespace std;

int main(){
    string uwu; cin >> uwu;
    int count[3]={0};
    for (int i=0;i<uwu.size();++i){
        count[uwu[i]-'A']++;
    }
    int minimum[3],temp=0; memset(minimum,0x3f,sizeof minimum);
    for (int l=0;l<3;++l){
        temp=0;
        char letter=l+'A';
        for (int i=0;i<count[l];++i){
            if (uwu[i]==letter) temp++;
        }
        minimum[l]=min(minimum[l],count[l]-temp);
        for (int i=0;i<uwu.size();++i){
            if (uwu[(i+count[l])%uwu.size()]==letter) temp++;
            if (uwu[i]==letter) temp--;
            minimum[l]=min(minimum[l],count[l]-temp);
        }
    }
    //cout << minimum[0] << " " << minimum[1] << " " << minimum[2] << '\n';
    cout << ceil(((minimum[0]+minimum[1]+minimum[2]))/2) << '\n';
}