#include <bits/stdc++.h>

using namespace std;
double K,P,X;
double f(double M){
    return (M*X)+((K*P)/M);
}

int main(){
    cin >> K >> P >> X;
    double smallest=1000000000.0;
    for (int i=1;i<10000;++i){
        smallest=min(f(i),smallest);
    }
    smallest=round(smallest*1000)/1000;
    printf("%.3f\n",smallest);
}