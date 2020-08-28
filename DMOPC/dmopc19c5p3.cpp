#include <bits/stdc++.h>

using namespace std;

int gcd(int x,int y){
    if (y==0) return x;
    return gcd(y,x%y);
}

int main(){
    int h,v; cin >> h >> v;
    long long total=0; int dx,dy,posx,posy;
    for (int x=1;x<v;++x){
        for (int y=0;y<h;++y){
            dx=y/(gcd(x,y));
            dy=x/(gcd(x,y));
            posx=x+dx;
            posy=y+dy;
            while (posx<=v&&posy<=h){
                total+=(v-posx)*(h-posy);
                posx+=dx;
                posy+=dy;
            }
        }
    }
    cout << total << '\n';
}