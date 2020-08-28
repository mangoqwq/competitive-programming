#include <bits/stdc++.h>

using namespace std;
//ofstream fout("photo.out");
//ifstream fin("photo.in");

int main(){
    int cows;
    cin >> cows;
    int sum[cows-1],temp;
    for (int i=0;i<cows-1;++i){
        cin >> temp;
        sum[i]=temp;
    }


    for (int start=1;start<cows+1;++start){
        bool end=false;
        int farm[cows+2];
        int checked[cows+2];
        for (int i=0;i<cows+2;++i){
            farm[i]=0;
            checked[i]=0;
        }
        farm[0]=start;
        checked[start]=1;
        for (int i=0;i<cows-1;++i){
            if (checked[sum[i]-farm[i]] || sum[i]-farm[i]<=0){
                end=true;
                break;
            }
            else{
                farm[i+1]=sum[i]-farm[i];
                checked[sum[i]-farm[i]]=1;
            }
        }
        if (end==false){
            for (int i=0;i<cows-1;++i){
                cout << farm[i] << " ";
            }
            cout << farm[cows-1];
            cout << '\n';
        }
    }
}