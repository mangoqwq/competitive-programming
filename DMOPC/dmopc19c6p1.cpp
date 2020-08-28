#include <bits/stdc++.h>

using namespace std;
struct point{
    double x1,y1,x2,y2;
};

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    point one,two; cin >> one.x1 >> one.y1 >> one.x2 >> one.y2 >> two.x1 >> two.y1 >> two.x2 >> two.y2;
    double slope1=(one.y2-one.y1)/(one.x2-one.x1);
    double slope2=(two.y2-two.y1)/(two.x2-two.x1);
    double yint1=slope1*-one.x2+one.y2;
    double yint2=slope2*-two.x2+two.y2;
    if (yint2==-0){
        yint2=0;
    }
    if (yint1==-0){
        yint1=0;
    }
    if (slope1==-0){
        slope1=0;
    }
    if (slope2==-0){
        slope2=0;
    }
    //cout << setprecision (13) << yint1 << " " << yint2 << " " << slope1 <<" " <<  slope2 << '\n';
    if (isinf(abs(slope1))&&isinf(abs(slope2))){
        if (abs(one.x1-two.x1)<0.0000001){
            cout << "coincident" << '\n';
        }
        else{
            cout << "parallel" << '\n';
        }
        return 0;
    }
    if (abs(slope1-slope2)<0.0000001){
        if (abs(yint1-yint2)<0.0000001){
            cout << "coincident" << '\n';
        }
        else{
            cout << "parallel" << '\n';
        }
        return 0;
    }
    else{
        if (isinf(abs(slope1))){
            double poix=one.x1;
            double poiy=((slope2)*poix)+yint2;
            if (poix==-0){
                poix=0;
            }
            if (poiy==-0){
                poiy=0;
            }
            cout << setprecision (13) << poix << " " << poiy << '\n';
            return 0;
        }
        if (isinf(abs(slope2))){
            double poix=two.x1;
            double poiy=((slope1)*poix)+yint1;
            if (poix==-0){
                poix=0;
            }
            if (poiy==-0){
                poiy=0;
            }
            cout << setprecision (13)<< poix << " " << poiy << '\n';
            return 0;
        }
        double poix=(yint1-yint2)/(slope2-slope1);
        double poiy=((slope1)*poix)+yint1;
        if (poix==-0){
            poix=0;
        }
        if (poiy==-0){
            poiy=0;
        }
        cout << setprecision (13) << poix << " " << poiy << '\n';
    }
}